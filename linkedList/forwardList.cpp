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

ForwardList::ForwardList()
{
    head = NULL;
}

Node* ForwardList::begin()
{
    return head;
}

void ForwardList::printList()
{
    Node* ptr = head;
    while(ptr)
    {
        cout << ptr->getValue() << endl;
        ptr = ptr->getNext();
    }
}

void ForwardList::insertAtFront(int value)
{
    Node* newNode = new Node(value);
    newNode->setNext(head);
    head = newNode;
}

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

Node*& ForwardList::next(Node*& position)
{
    if(position != NULL && position->getNext() != NULL)
    {
        position = position->getNext();
        return position;
    }
    return position;
}