from django.shortcuts import render
from users.models import assets
from django.contrib.auth.decorators import login_required

def display(request):
	context = assets.objects.all()
	return render(request, 'gallary/display.html', {'context':context})

@login_required
def display_me(request):
	context = request.user.assets_set.all()
	return render(request, 'gallary/display.html', {'context':context})