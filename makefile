#
# makefile for Project 1 Stack Calculator
# 2-21-2017
#

CC = g++

all:main

main: Stack.o Calculator.o
	${CC} Stack.o main.o -o main
Stack.o:
	${CC} -c Stack.cpp
Calculator.o:
	${CC} -c Calculator.cpp
clean:
	rm *.o
run:
	clean main
