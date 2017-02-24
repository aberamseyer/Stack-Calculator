/*
 *
 * Implemenation of the Stack ADT using a LinkedList as a private
 * member.
 *
 * @author Griffin
 *
 */
#include "Stack.h"

list<std::string
Stack::Stack() {

};

void Stack::push(std::string &x) {
	s.push_front(x);
};

void Stack::pop() {
	s.pop_front();
};

std::string& Stack::top() {
	std::string h = "hello";
	return &h;
};


