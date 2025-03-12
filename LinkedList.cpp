#include "LinkedList.h"
#include <iostream>

// constructor
LinkedList::LinkedList() : root(nullptr) {}

// copy constructor
LinkedList::LinkedList(const LinkedList& copy) : root(nullptr) {
    if (!copy.root) return;

    root = new Node(copy.root->data); // copy is the one that will be copied
    Node* temp = copy.root->next;
    Node* temp2 = root;

    while (temp) { // loop through and copy all
        temp2->next = new Node(temp->data);
        temp2 = temp2->next;
        temp = temp->next;
    }
}

LinkedList::~LinkedList(){ // destructor
    delete_entire_linked_list();
}

LinkedList::LinkedList(LinkedList&& other) : root(std::move(other.root)) { // move constructor
    other.root = nullptr; // move and null the original
}

LinkedList& LinkedList::operator=(LinkedList&& other) { // move copy constructor / operator
    if (this != &other) { // they are not the same already
        delete_entire_linked_list(); // clearing the current one so it can be replaced LL_1

        Node* temp = other.root; // other's
        Node** temp2 = &root; // current's 

        while(temp) {
            *temp2 = new Node(std::move(temp->data)); // moving data to new node
            temp = temp->next; // next node
            temp2 = &((*temp2)->next); // setting next
        }
    }

    return *this;
}

void LinkedList::insertAtBeginning(int val) { // given
    Node * newNode = new Node(val);
    newNode->next = root;
    root = newNode;
}

void LinkedList::insertAtEnd(int val) { // given
    Node* newNode = new Node(val);
    if (!root) {
        root = newNode;
        return;
    }
    Node* current = root;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

Node * LinkedList::getLastElement() { // given
    if (!root) {
        return nullptr; // added handling empty lists
    }
    
    Node * current = root;
    while (current->next) {
        current = current->next;
    }
    return current;
}

void LinkedList::deleteNode(int val) { // given
    if (!root) return;
    if (root->data == val) {
        Node* temp = root;
        root = root->next;
        delete temp;
        return;
    }
    Node* current = root;
    while (current->next && current->next->data != val) {
        current = current->next;
    }
    if (current->next) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

Node * LinkedList::build_linked_list(int total_nodes) { // given (slightly modified to fix an error)
    if (total_nodes == 0) {
        return nullptr;
    } else {
        root = new Node(1);
        Node* temp = root;
        
        for (int i = 1; i < total_nodes; i++) {
            temp->next = new Node(i+1);
            temp = temp->next;
        }
    }
    return root;
}

void LinkedList::print_linked_list() const{ // given
    Node * temp = root;

    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

void LinkedList::delete_entire_linked_list() {
    Node* temp = root; // start at root
    while(temp != nullptr) { // until all are deleted
        Node* temp2 = temp->next;
        delete temp; // delete
        temp = temp2; // onto next
    }
    root = nullptr;
}

int LinkedList::get_linked_list_data_item_value(int node_number) const{ // const here because nothing changes
    // return value stored in the node of that number
    Node* temp = root; // start at the root
    int i = 0; // counter
    while (temp) {
        if (i == node_number) { // first element
            return temp->data;
        }
        else {
            temp = temp->next;
            i++;
        }
    }
    return -1; // error for if index out of bounds
}

bool LinkedList::delete_list_element(int node_number){
    // remove the nodes that point to that node and delete the node itself (clear memory?)
    if (!root) {
        return false; // can't delete anything
    }
    
    Node* temp = root;
    if (node_number == 0) {
        root = root->next; // updating pointer
        delete temp; // delete
        return true; // was inside and was deleted
    }

    Node* temp2 = nullptr;
    int i = 0;
    while(temp && i < node_number) {
        temp2 = temp;
        temp = temp->next;
        i++;
    }

    if (!temp) {
        return false; // not there unable to delete
    }

    temp2->next = temp->next; // temp2 is previous so moving the pointer for the one before to the one after
    delete temp; // deleting current node (the one the user wants deleted)
    return true; // waas inside and deleted
}

void LinkedList::pointerJumping() { // all nodes must point to last node
    if (!root) return; // empty

    Node* last = getLastElement(); // using given function
    Node* temp = root;
    while(temp && temp != last) {
        temp->next = last;
        temp = temp->next;
    }
    
}

bool LinkedList::hasNegativePrefixSum() const{
    int psum = 0;
    Node* temp = root;
    while (temp) {
        psum += temp->data;
        if (psum < 0) {
            return true; // has the negative prefix sum
        }
        else {
            temp = temp->next;
        }
    }
    return false; // loop finished and nothing found
}

bool LinkedList::hasPositivePrefixSum() const{
    int psum = 0;
    Node* temp = root;
    while (temp) {
        psum += temp->data;
        if (psum > 0) {
            return true; // has the positive prefix sum
        }
        else {
            temp = temp->next;
        }
    }
    return false; // loop finished and nothing found
}

std::ostream & operator<<(std::ostream & os, const Node & node) { // given - moved out of node.h
    os  << node.data 
        << " at ("
        << & node
        << ")";

    return os;
};