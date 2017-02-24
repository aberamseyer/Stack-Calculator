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
  std::string at(int index) const;
  void add(std::string& toAdd);
  bool remove(int index);
	void printForward() const;
  void printBackward() const;

};

#endif
