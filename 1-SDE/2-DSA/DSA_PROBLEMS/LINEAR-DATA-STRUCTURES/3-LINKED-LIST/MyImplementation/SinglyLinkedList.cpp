/*
    Implementing a singly linked list of integers from scratch using raw C++
*/
#include<iostream>

using namespace std;

// every node of the Linked List is an object of a class
class Node{
public:
    int data;
    Node* next;
};

int main(){
    // first initialize three pointers which will point
    // to three nodes of the linked list
    Node* head = NULL;
    Node* mid = NULL;
    Node* end = NULL;

    // every node of the linked list is allocated memory on the heap dynamically
    // using the new operator
    head = new Node();
    mid = new Node();
    end = new Node();

    // note that now we need to allocate values to the different nodes
    head->data = 1;
    mid->data = 2;
    end->data = 3;

    // also we need to connect the nodes with each other 
    head->next = mid;
    mid->next = end;
    end->next = NULL;    


    return 0;
}


