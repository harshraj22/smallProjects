from django.db import models
from django.contrib import admin
from datetime import date
from django.core.validators import MaxValueValidator, MinValueValidator

class Problem(models.Model):
	description = models.TextField()
	opt1 = models.CharField(max_length=50)
	opt2 = models.CharField(max_length=50)
	opt3 = models.CharField(max_length=50)
	opt4 = models.CharField(max_length=50)
	difficulty = models.IntegerField(default=2, validators=[MaxValueValidator(3), MinValueValidator(1)])
	options = (
		('A', 'A'),
		('B', 'B'),
		('C', 'C'),
		('D', 'D'),
	)
	answer = models.CharField(max_length=3, choices=options)

class Quiz(models.Model):
	def __str__(self):
		return f'{self.name} on {self.date}'
	name = models.CharField(max_length=50)
	date = models.DateField(default=date.today)
	email = models.EmailField(max_length=70, null=True, blank=True, unique=False)
	correct = models.IntegerField()
	wrong = models.IntegerField()


admin.site.register(Problem)
admin.site.register(Quiz)
