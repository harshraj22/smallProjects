from django.shortcuts import render
from users.models import assets
from django.contrib.auth.decorators import login_required
import os
from django.conf import settings
from django.http import Http404, HttpResponse

def display(request):
	context = assets.objects.all()
	return render(request, 'gallary/display.html', {'context':context})

@login_required
def display_me(request):
	context = request.user.assets_set.all()
	return render(request, 'gallary/display.html', {'context':context})

def download(request, pk):
	path = assets.objects.get(id=pk).img.url
	file_path = os.path.join(settings.BASE_DIR, path)
	# print(file_path,'======')
	# print(settings.BASE_DIR,'------------------------',path)
	file_path = settings.BASE_DIR + path
	# os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
	if os.path.exists(file_path):
		with open(file_path, 'rb') as fh:
			response = HttpResponse(fh.read(), content_type="application/vnd.ms-excel")
			response['Content-Disposition'] = 'inline; filename=' + os.path.basename(file_path)
			return response
	raise Http404