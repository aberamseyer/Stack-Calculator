
/*
* Header file for the Stack implementation
*
* @author Griffin
*
*/
#ifndef STACK_H
#define STACK_H

#include <list>

class Stack{
  public:
    Stack ();
    void push (int & x);
    void pop ();
    int & top ();
    void printStack();
  private:
    LinkedList s;
};

#endif
