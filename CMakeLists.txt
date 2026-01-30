cmake_minimum_required(VERSION 4.1)
project(dhbw_kartenspiel C)

set(CMAKE_C_STANDARD 23)

add_executable(dhbw_kartenspiel main.c
        karten.h
        karten.c)
