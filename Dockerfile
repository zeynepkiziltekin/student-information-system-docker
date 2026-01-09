FROM gcc:13

WORKDIR /app

COPY . .

RUN g++ -o app main.cpp

CMD ["./app"]
