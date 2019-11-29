from django.shortcuts import render

def display(request):
	return render(request, 'gallary/display.html')
