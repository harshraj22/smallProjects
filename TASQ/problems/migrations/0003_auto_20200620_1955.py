# Generated by Django 3.0.4 on 2020-06-20 19:55

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('problems', '0002_auto_20200620_1954'),
    ]

    operations = [
        migrations.AlterField(
            model_name='option',
            name='question',
            field=models.ForeignKey(blank=True, null=True, on_delete=django.db.models.deletion.CASCADE, to='problems.Problem'),
        ),
    ]
