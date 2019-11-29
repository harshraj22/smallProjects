from django import forms
from django.forms import ModelForm
from django.contrib.auth.models import User
from django.contrib.auth.forms import UserCreationForm
from .models import UserProfile


class UserProfileForm(ModelForm):
	class Meta:
		model = UserProfile
		fields = ('attempted', 'solved')
