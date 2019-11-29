from django.shortcuts import render
from django.contrib.auth.forms import UserCreationForm
from django.contrib import messages
from .forms import UserProfileForm


def register(request):
	if request.method == 'POST':
		form = UserCreationForm(request.POST)
		if form.is_valid():
			username = form.cleaned_data.get('username')
			messages.success(request, 'added')

			user = form.save()

			profile_form = UserProfileForm()
			profile_form = profile_form.save(commit=False)
			profile_form.user = user
			profile_form.attempted = 0
			profile_form.solved = 0

			profile_form.save()


		else:
			messages.error(request, 'couldnt add')
	# else:
	form = UserCreationForm()
	# profile_form = UserProfileForm()
	return render(request, 'users/register.html', {'form':form})
