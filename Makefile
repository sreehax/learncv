CC = g++
CFLAGS = -g -Wall
SRCS = main.cpp
PROG = main

OPENCV = `pkg-config opencv4 --cflags --libs`
LIBS = $(OPENCV)

all:
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)
