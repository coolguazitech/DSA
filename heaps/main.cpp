#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>   
#include "heap.cpp"

using namespace std;

int myrandom(int i)
{ 
    return rand() % i;
}

void printVector(const vector<int>& v)
{
    for(int i: v)
    {
        cout << i << " ";
    }
    cout << endl;
}


int main()
{
    // set the size of heap
    int size = 18;

    // make a random vector
    srand(unsigned(time(0)));
    vector<int> myvector;

    for (int i = 1; i < size + 1; ++i) myvector.push_back(i);
    random_shuffle(myvector.begin(), myvector.end());

    // print the elements of the vector
    printVector(myvector);

    // instantiate a heap into which is rearranged from the above vector
    Heap h = Heap(myvector.begin(), myvector.end());

    // print the elements of this heap in an array-like way
    h.printHeapAsVector();

    // test the functionalities
    h.pop();
    cout << h.top() << endl;
    h.printHeapAsVector();

    system("pause"); 
}