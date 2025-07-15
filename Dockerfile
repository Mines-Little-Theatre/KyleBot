FROM debian:bookworm-slim AS builder

RUN apt update && \
    apt-get install -y build-essential wget && \
    apt-get install -y zlib1g-dev && \
    apt-get install -y libssl-dev && \
    apt-get install -y libopus-dev && \
    apt-get install -y cmake

WORKDIR /app

RUN wget https://github.com/brainboxdotcc/DPP/releases/download/v10.1.3/libdpp-10.1.3-linux-x64.deb && \
    dpkg -i /app/libdpp*.deb

ADD CMakeLists.txt /app/CMakeLists.txt
ADD src /app/src

RUN cmake -B /app/cmake-build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
RUN cd /app/cmake-build && \
    make

ENTRYPOINT [ "/app/cmake-build/ConcordBot" ]
