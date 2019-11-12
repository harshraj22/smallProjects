from django.shortcuts import render

# Create your views here.
def calcu(request):
	return render(request, 'calculate/index.html')