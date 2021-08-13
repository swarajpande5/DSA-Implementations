// Basics of priority queue in STL 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // priority_queue<int> pq;                              // This is max priority queue
    priority_queue<int, vector<int>, greater<int>> pq;      // This is min priority queue

    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        pq.push(ele);           // This is an O(logn) operation
    }

    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";

    return 0;
}   