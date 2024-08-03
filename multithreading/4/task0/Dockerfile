FROM ubuntu:16.04
    LABEL version="1.0"
    RUN apt-get update && apt-get install -y g++ mc && rm -rf /var/lib/apt/lists/*
    WORKDIR /app
    COPY ./hello.cpp .
    RUN  g++ hello.cpp -o hello
    CMD ["./hello"]
