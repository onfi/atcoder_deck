FROM alpine:3.11

WORKDIR /tmp
RUN apk update && apk add g++ git ruby nodejs python3 ninja cmake

# build zapcc
RUN git clone https://github.com/yrnkrn/zapcc.git llvm && mkdir build && cd build && cmake -G Ninja -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_WARNINGS=OFF ../llvm && ninja && cd -
CMD /bin/ash