#include <queue>
#include <iostream>
#include <array>
#include <vector>
#include <functional>
#include <algorithm>
#include <stdexcept>

using namespace std;

class mycomparison
{
    public:
    bool operator() (const vector<int>& v1, const vector<int>& v2) const
    {
        if(v1.empty() || v2.empty())
        {
            throw invalid_argument("some vector are empty");
        }
        else
        {
            return v1[0] >= v2[0];
        }
    }
};

int main()
{
    // implementation of a priority queue of vectors with their first elements sorted in ascending order
    vector<int> v1 {10, 20, 30};
    vector<int> v2 {20, 40, 60};
    vector<int> v3 {0, 40, 60};
    array<vector<int>, 3> vectors {v1, v2, v3};
    priority_queue<vector<int>, vector<vector<int>>, mycomparison> myq (vectors.begin(), vectors.end());

    while(!myq.empty())
    {
        cout << myq.top()[0] << ' ';
        myq.pop();
    }
    cout << endl;

    system("pause");
}