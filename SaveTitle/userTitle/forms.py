from django import forms
from .models import details

class detailsForm(forms.ModelForm):
	class Meta:
		model = details
		fields = ['name','title']
		widgets = {'name':forms.TextInput(attrs={'placeholder':'name'}),
			'title':forms.TextInput(attrs={'placeholder':'title'})
		}
