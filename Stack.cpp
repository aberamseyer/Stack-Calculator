/*
 *
 * Implemenation of the Stack ADT using a LinkedList as a private
 * member.
 *
 * @author Griffin
 *
 */
#include "Stack.h"
#include "LinkedList.h"


/* Initialize the stack */
Stack::Stack() {
	LinkedList stack;
	s = stack;
};


/* Add value to the stack */
void Stack::push(int &x) {
	s.add(x);
};

/* remove the top value of the stack */
void Stack::pop() {
	int a = s.getSize() - 1;
	s.remove(s.at(a));
};

/* Returns the top value of the stack without removing */
int& Stack::top() {
	return s.at(s.getSize() - 1);
};


