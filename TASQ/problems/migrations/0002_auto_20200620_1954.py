# Generated by Django 3.0.4 on 2020-06-20 19:54

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('problems', '0001_initial'),
    ]

    operations = [
        migrations.AlterField(
            model_name='option',
            name='question',
            field=models.ForeignKey(blank=True, on_delete=django.db.models.deletion.CASCADE, to='problems.Problem'),
        ),
    ]
