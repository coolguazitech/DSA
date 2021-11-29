#include <iostream>
#include "forwardList.cpp"

using namespace std;



int main()
{
    ForwardList myList;

    for(int i = 0; i < 10; i++)
    {
        myList.insertAtFront(i);
    }

    myList.printList();
    
    Node* ptr = myList.begin();

    for(int i = 0; i < 3; i++)
    {
        ptr = myList.next(ptr);
    }

    ptr = myList.deleteHere(ptr);

    myList.reverse();

    myList.printList();

    system("pause");
}