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

}
