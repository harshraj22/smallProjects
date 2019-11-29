from django.db import models

# Create your models here.
class details(models.Model):
	name = models.CharField(max_length=20)
	title = models.CharField(max_length=650)

	def __str__(self):
		return self.title