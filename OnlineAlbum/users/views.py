from django.shortcuts import render
from .forms import UserImageUploadForm
from django.contrib.auth.decorators import login_required

@login_required(login_url='login')
def display(request):
	return render(request, 'users/display.html')

def upload(request):
	if request.method == 'POST':
		form = UserImageUploadForm(request.POST, request.FILES)
		if form.is_valid() and request.user.is_authenticated:
			form = form.save(commit=False)
			form.user = request.user
			form.save()

			print("Saved")
		else:
			print("couldn't save", form.is_valid(), request.user.is_authenticated)
			print(form.errors)

	context = {'form':UserImageUploadForm()}
	return render(request, 'users/upload.html', context)