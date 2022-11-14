from fastapi import FastAPI
import requests

app = FastAPI()


@app.get("/")
async def root():
    return {"message": "Hello World"}

@app.get("/other")
async def other():
    return requests.get('http://localhost:8002/').json()