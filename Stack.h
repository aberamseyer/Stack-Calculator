
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
    void push (std::string & x);
    void pop ();
    std::string top ();
    void clear ();
    // add more functions as needed
  private:
    LinkedList stack;
};

#endif
