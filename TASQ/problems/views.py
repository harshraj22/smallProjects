from django.shortcuts import render, redirect
from django.urls import reverse
from .models import Problem, Quiz
from .forms import ProblemForm
from django.contrib import messages
import random
from django.views.decorators.csrf import csrf_exempt
from django.http import HttpResponseRedirect


MIN_DIFFICULTY = 1
MAX_DIFFICULTY = 3
MAX_PROBLEMS_ATTEMPT = 3

def problems(request):
	problem = Problem.objects.first()
	return render(request, 'problems/problem.html', {'problem': problem})

def display_problem(request, id):
	problem = Problem.objects.get(id=id)

	if request.method == 'POST':
		form = ProblemForm(request.POST)
		print(request.POST.keys(), form.data.keys(), '\n\n\n\n')
		print(f"post, {form.data['choice'], form.data['answer'], form.data['choice'] == form.data['answer']}")
		
		if form.data['choice'] == form.data['answer']:
			messages.success(request, 'Correct answer')
			request.session['AC'] += 1
			difficulty = min(int(form.data['difficulty'])+1, MAX_DIFFICULTY)
		else:
			messages.error(request, 'Wrong Answer')
			request.session['WA'] += 1
			difficulty = max(int(form.data['difficulty'])-1, MIN_DIFFICULTY)
		print(request.session['AC'], request.session['WA'])

		next_problem_set = Problem.objects.filter(difficulty=difficulty)
		next_problem = random.choice(next_problem_set)
		return redirect(reverse('display-problem', kwargs={'id': next_problem.id}))
	form = ProblemForm(instance=problem)

	if request.session['AC'] + request.session['WA'] >= MAX_PROBLEMS_ATTEMPT:
		return redirect(reverse('display-result'))

	return render(request, 'problems/problem.html', {'problem': problem, 'form': form})

def display_result(request):
	correct = request.session.get('AC', 0)
	wrong = request.session.get('WA', 0)
	return render(request, 'problems/result.html', {'AC': correct, 'WA': wrong})


@csrf_exempt 
def login(request):
	print('==================login===============', request.POST, request.GET, request.body)
	username = request.POST['username']
	backlink = request.POST['backlink']
	request.session['AC'] = 0
	request.session['WA'] = 0
	request.session['username'] = username
	request.session['backlink'] = backlink
	id = Problem.objects.first().id
	return redirect(reverse('display-problem', kwargs={'id': id}))

def logout(request):
	q = Quiz.objects.create(name=request.session['username'], email=request.session.get('email', ''), correct=request.session['AC'], wrong=request.session['WA'])
	q.save()
	request.session.pop('AC', None)
	request.session.pop('WA', None)
	request.session.pop('username', None)
	return HttpResponseRedirect(request.session['backlink'])
	# return render(request, request.session['backlink'])