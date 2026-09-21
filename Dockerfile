FROM ubuntu:24.04

RUN apt-get update && apt-get install -y --no-install-recommends \
        g++ make gdb valgrind \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .
RUN make

CMD ["./campusguard"]
