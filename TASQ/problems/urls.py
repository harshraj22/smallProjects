from django.urls import path
from . import views 

urlpatterns = [
    path('', views.problems, name='all-problems'),
    path('<int:id>/', views.display_problem, name='display-problem'),
    path('result', views.display_result, name='display-result'),
]