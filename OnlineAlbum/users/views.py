from django.shortcuts import render
from .forms import UserImageUploadForm

def display(request):
	return render(request, 'users/display.html')

def upload(request):
	if request.method == 'POST':
		form = UserImageUploadForm(request.POST)
		if form.is_valid() and request.user.is_authenticated():
			form = form.save(commit=False)
			form.user = request.user
			form.save()

			print("Saved")
		else:
			print("couldn't save")

	context = {'form':UserImageUploadForm()}
	return render(request, 'users/upload.html', context)