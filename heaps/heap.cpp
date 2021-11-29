#include "heap.h"
#include <iostream>

using namespace std;

Heap::Heap()
{
    m_arr.push_back(0); // fill the first element with 0
}

Heap::Heap(bool reverse) : m_reverse(reverse)
{
    m_arr.push_back(0); // fill the first element with 0
}

Heap::Heap(vector<int>::const_iterator from, vector<int>::const_iterator to)
{
    m_arr.push_back(0); // fill the first element with 0

    for(auto iter = from; iter != to; ++iter)
    {
        m_arr.push_back(*iter);
        m_size++;
    }

    buildHeap(m_reverse);
}

Heap::Heap(vector<int>::const_iterator from, vector<int>::const_iterator to, bool reverse) : m_reverse(reverse)
{
    m_arr.push_back(0); // fill the first element with 0

    for(auto iter = from; iter != to; ++iter)
    {
        m_arr.push_back(*iter);
        m_size++;
    }

    buildHeap(reverse);
}
    
/*
    swap two elements' references
*/
void Heap::swap (int& i, int& j)
{
    int temp = i;
    i = j;
    j = temp;
}

/*
    do max heapifying on the subtree rooted with root
*/
void Heap::maxHeapify(vector<int>& m_arr, int root)
{
    if(root * 2 <= m_size && root * 2 + 1 <= m_size)
    {
        if(m_arr[root] < m_arr[root * 2] || m_arr[root] < m_arr[root * 2 + 1])
        {
            if(m_arr[root * 2] < m_arr[root * 2 + 1])
            {
                swap(m_arr[root], m_arr[root * 2 + 1]);
                maxHeapify(m_arr, root * 2 + 1);
            }
            else
            {
                swap(m_arr[root], m_arr[root * 2]);
                maxHeapify(m_arr, root * 2);
            }
        }
    }
    else if (root * 2 <= m_size)
    {
        if(m_arr[root] < m_arr[root * 2])
        {
            swap(m_arr[root], m_arr[root * 2]);
            maxHeapify(m_arr, root * 2);
        }
    }
}

/*
    do min heapifying on the subtree rooted with root
*/
void Heap::minHeapify(vector<int>& m_arr, int root)
{
    if(root * 2 <= m_size && root * 2 + 1 <= m_size)
    {
        if(m_arr[root] > m_arr[root * 2] || m_arr[root] > m_arr[root * 2 + 1])
        {
            if(m_arr[root * 2] > m_arr[root * 2 + 1])
            {
                swap(m_arr[root], m_arr[root * 2 + 1]);
                minHeapify(m_arr, root * 2 + 1);
            }
            else
            {
                swap(m_arr[root], m_arr[root * 2]);
                minHeapify(m_arr, root * 2);
            }
        }
    }
    else if (root * 2 <= m_size)
    {
        if(m_arr[root] > m_arr[root * 2])
        {
            swap(m_arr[root], m_arr[root * 2]);
            minHeapify(m_arr, root * 2);
        }
    }
}

/*
    rearrange elements into a heap
*/
void Heap::buildHeap(bool reverse)
{
    for(int i = m_size / 2; i >= 1; --i)
    {
        reverse ? minHeapify(m_arr, i): maxHeapify(m_arr, i);
    }
}

/*
    check if this is an empty heap
*/
bool Heap::empty()
{
    return m_size == 0;
}


/*
    add a new element into this heap
*/
void Heap::push(const int& x)
{
    m_arr.push_back(x);
    m_size++;
    int curCompareRoot = m_size / 2;
    int xIndex = m_size;
    if(m_reverse)
    {
        while(curCompareRoot != 0 && m_arr[xIndex] < m_arr[curCompareRoot])
        {
            swap(m_arr[xIndex], m_arr[curCompareRoot]);
            xIndex /= 2;
            curCompareRoot /= 2;
        }
    }
    else
    {
        while(curCompareRoot != 0 && m_arr[xIndex] > m_arr[curCompareRoot])
        {
            swap(m_arr[xIndex], m_arr[curCompareRoot]);
            xIndex /= 2;
            curCompareRoot /= 2;
        }
    }
}

/*
    return the first element of this heap
*/
int Heap::top()
{
    if(m_size == 0)
    {
        cout << "Can't call this funciton with an empty heap!" << endl;
    }
    else
    {
        return m_arr[1];
    }
}


/*
    pop the first element of this heap, and maintain it to be a heap again
*/
void Heap::pop()
{
    if(m_size == 0)
    {
        cout << "Can't call this funciton with an empty heap!" << endl;
        return;
    }
    else if(m_size == 1)
    {
        m_arr.pop_back();
        m_size--;
    }
    else
    {
        for(int i = 2; i <= m_size; i++)
        {
            m_arr[i - 1] = m_arr[i];
        }
        m_arr.pop_back();
        m_size--;
        buildHeap(m_reverse);
    }
}

/*
    print the current heap elements
*/
void Heap::printHeapAsVector()
{
    for(int i = 1; i <= m_size; i++)
    {
        cout << m_arr[i] << ' ';
    }
    cout << endl;
}