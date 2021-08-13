// Minimum Cost of Ropes: https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
#include <bits/stdc++.h>
using namespace std;

int joinRopes(int ropes[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq(ropes, ropes + n);    // Min heap

    int cost = 0;

    while(pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        int newRope = a + b;
        cost = cost + newRope;
        pq.push(newRope);
    }

    return cost;
}

int main()
{
    int ropes[] = {4, 3, 2, 6};
    int n = 4;
    
    cout << joinRopes(ropes, n) << "\n";

    return 0;
}