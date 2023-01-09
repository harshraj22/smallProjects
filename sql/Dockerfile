FROM python:3.8-alpine

COPY connect.py connect.py
RUN pip3 install PyMySQL

CMD [ "python3", "connect.py" ]