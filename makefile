#
# makefile for Project 1 Stack Calculator
# 2-21-2017
#

CC = g++
FLAGS = -std=c++11

all:main

main:  Calculator.o LinkedList.o Stack.o
	${CC} ${FLAGS} LinkedList.o Stack.o Calculator.o -o main

LinkedList.o:
	${CC} ${FLAGS} -c LinkedList.cpp
Stack.o:
	${CC} ${FLAGS} -c Stack.cpp
Calculator.o:
	${CC} ${FLAGS} -c Calculator.cpp
clean:
	rm *.o
run: clean main
