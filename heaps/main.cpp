#include <iostream>
#include <iomanip>
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
    int size = 18;

    srand(unsigned(time(0)));
    vector<int> myvector;

    for (int i = 1; i < size + 1; ++i) myvector.push_back(i);
    random_shuffle(myvector.begin(), myvector.end());

    printVector(myvector);

    Heap h = Heap(myvector.begin(), myvector.end());

    h.printHeapAsVector();

    h.pop();
    cout << h.top() << endl;

    h.printHeapAsVector();

    system("pause"); 
}