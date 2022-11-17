
# Run on Kubernetes:

1. Create docker image using `docker build -f Dockerfile.other . -t harshraj22/other` and `docker build -f Dockerfile.main . -t harshraj22/main`. Note, tagged in this way to make it easy to push to dockerhub.
2. Push the image to dockerhub ([login](https://docs.docker.com/engine/reference/commandline/login/) to dockerhub ) using `docker push harshraj22/hello`, `docker push harshraj22/other`.
3. start docker-desktop and minikube: `minikube start`
4. ~~create a deployment: `kubectl create deployment hello --image=harshraj22/hello `~~
5. install ingress if not done already: `minikube addons enable ingress`. (https://kubernetes.io/docs/tasks/access-application-cluster/ingress-minikube/)
6. ~~expose to external world: `kubectl expose deployment hello --type=LoadBalancer --port=8001`~~
6. Use yml files: `kubectl create -f k8/` and `minikube tunnel` to allow http requests
7. checkout the cool app: `localhost`
8. checkout dashboard: `minikube dashboard `
