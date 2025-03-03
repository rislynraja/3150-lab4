#ifndef _NODE_H
#define _NODE_H

#include <iostream>

struct Node {
    Node * next;
    int data;

    Node() { // default constructor
        next = nullptr;
        data = -1;
    }

    Node(int val) : data{val}, next{nullptr} {} // constructor
};

std::ostream& operator<<(std::ostream& os, const Node& node); // defining but not including 

#endif