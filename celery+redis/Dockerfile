
FROM python:3.8-slim

# layer caching for faster builds
COPY requirements.txt /
RUN pip install -r /requirements.txt

#COPY app.py /app.py
ADD . /simple_worker
WORKDIR /simple_worker

ENTRYPOINT celery -A backend worker --loglevel=info