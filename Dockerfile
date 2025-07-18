# Use a specific Ubuntu base image
FROM ubuntu:20.04

# Set environment variables to avoid interaction
ENV DEBIAN_FRONTEND=noninteractive \
    TZ=UTC

# Install system dependencies and clean up
RUN apt update && \
    apt install -y \
    build-essential \
    gcc \
    g++ \
    gdb \
    libstdc++-10-dev \
    wget \
    python3 \
    python3-pip \
    git \
    tzdata && \
    apt clean && \
    rm -rf /var/lib/apt/lists/*

RUN python3 -m pip install --no-cache-dir meson ninja

# Set environment variables
ENV CC=/usr/bin/gcc
ENV CXX=/usr/bin/g++
ENV LD_LIBRARY_PATH=/usr/local/lib

# Set the working directory
WORKDIR /usr/src/shark

# Copy the source code
COPY . .

# Set the working directory
RUN meson setup builddir
RUN meson compile -C builddir
RUN meson test -C builddir
RUN meson install -C builddir

# Set the entrypoint
ENTRYPOINT ["/usr/local/bin/shark"]