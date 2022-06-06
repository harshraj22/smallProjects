from celery import Celery
from time import sleep


app = Celery(
    'tasks',
    backend='redis://redis:6379/0',
    broker='redis://redis:6379/0'
)


@app.task()
def get(n: int) -> str:
    sleep(n)
    return 'Hello World'
