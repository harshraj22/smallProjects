from django.db import models
from django.contrib import admin 
from django.contrib.auth.models import User

class assets(models.Model):
	img = models.ImageField(upload_to='images/')
	user = models.ForeignKey(User, on_delete=models.CASCADE, null=True)

	def __str__(self):
		return self.user.username
		
admin.site.register(assets)