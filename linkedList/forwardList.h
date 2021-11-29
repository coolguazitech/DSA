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
        ForwardList(); 
        Node* begin(); 
        void printList();
        void insertAtFront(int); 
        void insertAtRear(int);
        void reverse();
        Node*& insertAfter(Node*&, int); 
        Node*& deleteHere(Node*&);
        Node*& next(Node*&); 
    private:
        Node* head;
};

