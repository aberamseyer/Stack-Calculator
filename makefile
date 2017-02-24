#
# makefile for Project 1 Stack Calculator
# 2-21-2017
#

CC = g++

all:main

main:  Calculator.o LinkedList.o #Stack.o
	${CC} LinkedList.o Calculator.o -o main #add in Stack.o

LinkedList.o:
	${CC} -c LinkedList.cpp
#Stack.o:
#	${CC} -c Stack.cpp
Calculator.o:
	${CC} -c Calculator.cpp
clean:
	rm *.o
run:
	clean main
