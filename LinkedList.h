#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>
#include "Node.h"

using namespace std;

class LinkedList {
  public:

    Node * root;

    LinkedList(); // constructor
    LinkedList(const LinkedList& copy); // copy constructor
    ~LinkedList(); // destructor

    LinkedList(LinkedList&& other); // move constructor
    LinkedList& operator=(LinkedList&& other); // move copy constructor / operator

    // given functions (defined)
    void insertAtBeginning(int val);
    void insertAtEnd(int val);
    Node * getLastElement();
    void deleteNode(int val);
    Node * build_linked_list(int nodes) ;
    void print_linked_list() const;

    // functions that need to be written
    void delete_entire_linked_list();
    int get_linked_list_data_item_value(int node_number) const;
    void pointerJumping();
    bool hasNegativePrefixSum() const;
    bool hasPositivePrefixSum() const;
    bool delete_list_element(int node_number);

};

#endif