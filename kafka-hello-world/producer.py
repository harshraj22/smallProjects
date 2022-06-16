from kafka import KafkaProducer
import json
from time import sleep
import uuid
    

producer = KafkaProducer(bootstrap_servers='localhost:9092')
# _instance = Faker()


for _ in range(20):
    _data = {
        "first_name": '_instance.first_name()',
        "id":str(_),
        "uuid":uuid.uuid4().__str__()
    }
    _payload = json.dumps(_data).encode("utf-8")
    response = producer.send('FirstTopic', _payload)
    print(_data)


    sleep(0.2)
