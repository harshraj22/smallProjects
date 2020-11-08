# OnlineAlbum:
An album that provides users space to store thier images.

> In case you want to help, see [issues](https://github.com/harshraj22/smallProjects/issues) section

* Revised models, views, urls, forms, ORM.
* Learnt to use django-provided login/logout routes.
* Learnt dealing with files in forms, foreign keys and query on ORM.
* Learnt downloading files from website.

### For using postgresql, make the following changes
* apart from given dependencies (Django, Pillow), install `pip3 install psycopg2-binary`
* create new posqgresql user and database, giving all access of the database to the newly created user (follow [this](https://medium.com/agatha-codes/painless-postgresql-django-d4f03364989) tutorial for first part)
* edit settings.py as per following
```
DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.postgresql',
        'NAME': 'sample_database',
        'USER': 'sample_user',
        'PASSWORD': 'sample_password',
        'HOST': 'localhost',
        'PORT': '5432'
    }
}
```
* Now run `python3 manage.py makemigratioins` and `python3 manage.py migrate` . This creates the corresponding tables in the newly created database.
* Note that the path where files are saved on being uploaded isn't changed. It only changes the place where tables are stored.
