
/*
* Header file for the Stack implementation
*
* @author Griffin
*
*/
#ifndef STACK_H
#define STACK_H


#include "LinkedList.h"

class Stack{
  public:
    Stack ();
    void push (int x);
    void pop ();
    int top ();
    void clear();
    bool empty();
    void printStack();
  private:
    LinkedList s;
};

#endif
