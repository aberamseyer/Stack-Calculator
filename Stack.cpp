/*
 *
 * Implemenation of the Stack ADT using a LinkedList as a private
 * member.
 *
 * @author Griffin
 *
 */
#include "Stack.h"


/* Initialize the stack */
Stack::Stack() {

}

/* Kill the Stack */
Stack::~Stack() {

}

/* Add value to the stack */
void Stack::push(int x) {
	s.add(x);
}


/* remove the top value of the stack */
void Stack::pop() {
	if (s.getSize() != 0) {
		int a = s.getSize() - 1;
		s.remove(a);
	}
}


/* Returns the top value of the stack without removing */
int Stack::top() {
	return s.at(s.getSize() - 1);
}


/* Print stack */
void Stack::printStack() {
	for (int i = 0; i < s.getSize(); i++) {
		std::cout << s.at(i) << ", ";
	}
}

/* remove everything in the stack */
void Stack::clear() {
	for(int i = s.getSize()-1; i>=0; i--) {
		s.remove(i);
	}
}

/* test if the stack is empty */
bool Stack::empty() {
	if(s.getSize() == 0)
		return true;
	return false;
}
