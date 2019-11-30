from django.urls import path
from . import views

urlpatterns = [
	path('', views.display, name='display-gallary'),
	path('my', views.display_me, name='display-user-gallary'),
	path('download/<int:pk>', views.download, name='download')
]
