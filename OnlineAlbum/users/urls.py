from django.urls import path
from . import views

urlpatterns = [
	path('', views.display, name='display-user'),
	path('upload/', views.upload, name='upload-user'),
	# path('login/', )
]
