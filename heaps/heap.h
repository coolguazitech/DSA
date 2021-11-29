#include <vector>


using namespace std;

/*
    implementation of heap data structure, it contains only integers and
    is managed by a vector, possessing functionalities comprising empty,
    push, top, pop, print heap as a vector. Users can instantiate one w-
    ith empty set or a copy of a specific vector. if class member rever-
    se is true, then it will always be maintained by min heapifying.
*/
class Heap
{
    private:
        bool m_reverse = false; // min priority
        int m_size = 0; // size of this heap, counting all but the first elements
        vector<int> m_arr; // managed array
        void swap(int&, int&);
        void maxHeapify(vector<int>&, int);
        void minHeapify(vector<int>&, int);
        void buildHeap(bool);

    public:
        Heap();
        Heap(bool);
        Heap(vector<int>::const_iterator, vector<int>::const_iterator);
        Heap(vector<int>::const_iterator, vector<int>::const_iterator, bool);
        bool empty();
        void push(const int&);
        int top();
        void pop();
        void printHeapAsVector();
};

