FROM ubuntu

RUN apt-get update 
	
RUN apt-get install build-essential -y

#RUN apt-get install valgrind -y

WORKDIR /app

COPY ./ ./
