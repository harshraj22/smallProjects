from kafka import KafkaConsumer

consumer = KafkaConsumer('order_details', bootstrap_servers='localhost:9092', group_id='replica')

print("Gonna start listening")
while True:
    for message in consumer:
        print("Here is a message..")
        print (message)