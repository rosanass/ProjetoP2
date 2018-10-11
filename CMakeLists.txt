cmake_minimum_required(VERSION 3.8)
project(ProjetoP2)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES Compress/main.c Compress/inc/compress.h Compress/src/compress.c
        Compress/inc/decompress.h Compress/src/decompress.c Compress/inc/priority_queue.h
        Compress/src/priority_queue.c Compress/inc/huff_tree.h Compress/src/huff_tree.c Compress/inc/node.h Compress/src/node.c
        Compress/inc/binary.h Compress/src/binary.c)


add_executable(Huffman ${SOURCE_FILES})