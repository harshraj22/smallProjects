## Celery + Redis

Following tutorial from [Soumil's](https://www.youtube.com/watch?v=69vpylT2Dts) video.

Use the following steps to run:
1. `docker-compose up --build` to build both the images and start the docker containers.
2. Note that services started in docker do not share the same network outside [[1](https://stackoverflow.com/a/70621987/10127204)]. This is the primary reason of putting `backend.py` as another service in docker-compose.
3. Once the services have started and are running, find id of `simple_worker` service using `docker ps -a`, and attach to that container using `docker exec -it <id> sh`.
4. open a python interactive shell here using `python` command.
5. Test out the celery tasks using the given code:
```python
>>> from backend import get
>>> res = get.delay(5)
>>> res.status
'PENDING'
>>> res.status
'SUCCESS'
>>> res.get()
'Hello World'
>>> 
```