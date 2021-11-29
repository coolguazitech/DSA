class Node
{
    private:
        int value;
        Node* next;
    public:
        Node(int);
        inline int getValue(){return value;}
        void setValue(int);
        inline Node* getNext(){return next;}
        void setNext(Node*);
};

class ForwardList
{
    public:         
        ForwardList(); // construct an empty forwardlist
        Node* begin(); // return a pointer pointing at head
        void printList(); // print all values of the nodes
        void insertAtFront(int); // insert a new node at front
        void insertAtRear(int); // insert a new node at rear
        void reverse(); // reverse this list 
        Node*& insertAfter(Node*&, int); // insert a new node after previous one, return the pointer just at new node
        Node*& deleteHere(Node*&); // delete node to which the pointer is pointing, return the pointer forward to the node's next
        Node*& next(Node*&); // return the pointer pushed to the next node
    private:
        Node* head;
};

