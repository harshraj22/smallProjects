from django import forms
from .models import Problem

class ProblemForm(forms.ModelForm):
	options = (
		('A', 'A'),
		('B', 'B'),
		('C', 'C'),
		('D', 'D'),
	)
	choice = forms.ChoiceField(choices=options)
	class Meta:
		model = Problem
		fields = '__all__'
		# exclude = ['answer']
		widgets = {
			'answer': forms.HiddenInput(),
			'description': forms.TextInput(attrs={'readonly':'readonly'}),
			'opt1': forms.TextInput(attrs={'readonly':'readonly'}),
			'opt2': forms.TextInput(attrs={'readonly':'readonly'}),
			'opt3': forms.TextInput(attrs={'readonly':'readonly'}),
			'opt4': forms.TextInput(attrs={'readonly':'readonly'}),
			'difficulty': forms.TextInput(attrs={'readonly':'readonly'}),
		}

