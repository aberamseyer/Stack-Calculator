/*
 * LinkedList.h
 *
 * @Abe Ramseyer
 * 2-14-2017
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>

class LinkedList {

 private:
  struct Node {
    std::string data;
    Node* next;
    Node* prev;
  };

  Node* head;
  Node* tail;
  int size;

public:
	LinkedList();
  LinkedList(LinkedList& other);
  ~LinkedList();

  LinkedList::Node* getHead() const;
  LinkedList::Node* getTail() const;
  int getSize() const;
  int at(int index) const;
  void add(std::string toAdd);
  bool remove(std::string index);
	void printForward() const;
  void printBackward() const;

};

#endif
