Followed Youtube Video:  [here](https://www.youtube.com/watch?v=qi7uR3ItaOY&t=2s)


## Setting up Kafka:
Kafka on docker is notorously tough to setup. The current doceker-compose works by following:
1. Pull kafka image from docker hub: `docker pull wurstmeister/kafka`
2. Pull zookeeper image from docker hub: `docker pull wurstmeister/zookeeper`

## Getting started:
1. Start the kafka server: `docker-compose up -d`
2. Start Listening for messages to be consumed `python3 consumer.py`
3. Start producing messages to be consumed `python3 producer.py`