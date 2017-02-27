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

// LinkedList stack;

Stack::Stack() {
}

void Stack::push(std::string &x) {
	stack.add(x);
}

void Stack::pop() {
	int a = stack.getSize() - 1;
	stack.remove(a);
}

std::string Stack::top() {
	return stack.at(stack.getSize() - 1);
}

void Stack::clear() {
	for(int i=stack.getSize()-1; i >= 0; i--) {
		stack.remove(i);
	}
}

bool Stack::empty() {
	if(stack.getSize() == 0)
		return true;
	return false;
}
