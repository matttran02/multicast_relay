cmake_minimum_required(VERSION 3.17)
project(multicast_relay C)

set(CMAKE_C_STANDARD 11)

add_executable(multicast_relay
        client.c
        server.c)
