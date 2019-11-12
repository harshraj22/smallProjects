from django.shortcuts import render, redirect
from .forms import detailsForm

# Create your views here.
def show(request):
	# return render(request, 'userTitle/index.html')
	form = detailsForm()
	context = {'form':form}
	return render(request, 'userTitle/index.html', context)

def save_data(request):
	form = detailsForm(request.POST)

	# print(request.POST['name'])
	if form.is_valid():
		form.save()

	return redirect('show')