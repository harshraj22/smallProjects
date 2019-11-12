from django.urls import path, include
from . import views

urlpatterns = [
    path('', views.show , name='show'),
    path('dataSave', views.save_data , name='save'),
]