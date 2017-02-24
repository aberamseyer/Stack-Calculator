
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
    void push (std::string & x);
    void pop ();
    std::string & top ();
    // add more functions as needed
  private:
    LinkedList s;
};

#endif
