### Getting started with FastAPI and Docker

Start with the following commands:
1. `docker build -t fastapi-docker .` to build the image using the given file
2. `docker run -dp 8005:8005 fastapi-docker` to spin up a container using the image we just built


head over to `localhost:8005/docs` to see the documentation.
