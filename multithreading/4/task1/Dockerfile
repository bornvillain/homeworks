FROM ubuntu:latest
    LABEL version="1.0"
    RUN apt-get update && apt-get install -y clang mc && rm -rf /var/lib/apt/lists/*
    WORKDIR /app
    COPY ./for_each.cpp .
    RUN  clang++ for_each.cpp -o for_each
    CMD ["./for_each"]
