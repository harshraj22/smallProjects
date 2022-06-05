FROM python:3.8-alpine

WORKDIR /app

COPY . .
RUN pip install -r requirements.txt

EXPOSE 8005

CMD ["uvicorn", "main:app", "--reload", "--port", "8005", "--host", "0.0.0.0"]