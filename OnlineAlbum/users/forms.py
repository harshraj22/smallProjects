from django import forms
from .models import assets

class UserImageUploadForm(forms.ModelForm):
	class Meta:
		model = assets
		fields = ('img',)