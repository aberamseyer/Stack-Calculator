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

LinkedList stack;

Stack::Stack() {
	s = stack;
};

void Stack::push(std::string &x) {
	s.add(x);
};

void Stack::pop() {
	int a = stack.getSize() - 1;
	std::string b = stack.at(a);
	s.remove(b);
};

std::string& Stack::top() {
	return s.at(stack.getSize() - 1);
};


