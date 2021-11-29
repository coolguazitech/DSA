#include <vector>


using namespace std;

class Heap
{
    private:
        bool m_reverse = false;
        int m_size = 0;
        vector<int> m_arr;
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

