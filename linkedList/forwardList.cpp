#include <iostream>
#include "forwardList.h"
using namespace std;


Node::Node(int value):value(value){}

void Node::setValue(int value)
{
     this->value = value;
}   

void Node::setNext(Node* next)
{
        this->next = next;
}   

/*
    construct an empty forwardlist
*/
ForwardList::ForwardList()
{
    head = NULL;
}

/*
    return a pointer pointing at head
*/
Node* ForwardList::begin()
{
    return head;
}

/*
    print all values of the nodes
*/
void ForwardList::printList()
{
    Node* ptr = head;
    while(ptr)
    {
        cout << ptr->getValue() << endl;
        ptr = ptr->getNext();
    }
}

/*
    insert a new node at front
*/
void ForwardList::insertAtFront(int value)
{
    Node* newNode = new Node(value);
    newNode->setNext(head);
    head = newNode;
}

/*
    insert a new node at rear
*/
void ForwardList::insertAtRear(int value)
{
    Node* newNode = new Node(value);
    newNode->setNext(NULL);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    Node* ptr = head;
    while(ptr->getNext() != NULL)
    {
        ptr = ptr->getNext();
    }
    ptr->setNext(newNode);
}

/*
    reverse this list 
*/
void ForwardList::reverse()
{
    Node* ptr1 = NULL;
    Node* ptr2 = head;

    while(ptr2)
    {
        Node* ptr3 = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->getNext();
        ptr1->setNext(ptr3);
    }
    head = ptr1;
}

/*
    insert a new node after previous one, return the pointer just at new node
*/
Node*& ForwardList::insertAfter(Node*& previous, int value)
{
    if(previous == NULL)
    {
        cout << "previous node is invalid!" << endl;
        return previous;
    }
    Node* newNode = new Node(value);
    newNode->setNext(previous->getNext());
    previous->setNext(newNode);
    previous = previous->getNext();
    return previous;
}

/*
    delete node to which the pointer is pointing, return the pointer forward to the node's next
*/
Node*& ForwardList::deleteHere(Node*& here) 
{
    if(here == NULL)
    {
        cout << "current node doesn't exist" << endl;
    }
    else if(here == head)
    {
        Node* curPtr = here;
        here = here->getNext();
        delete curPtr;
    }
    else
    {
        Node* ptr = head;
        while(ptr->getNext() != here)
        {
            ptr = ptr->getNext();
        }
        ptr->setNext(here->getNext());
        Node* curPtr = here;
        here = here->getNext();
        delete curPtr;
    }
    return here;
}

/*
    return the pointer pushed to the next node
*/
Node*& ForwardList::next(Node*& position)
{
    if(position != NULL && position->getNext() != NULL)
    {
        position = position->getNext();
        return position;
    }
    return position;
}