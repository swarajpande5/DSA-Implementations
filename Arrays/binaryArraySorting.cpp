// Binary Array Sorting : https://practice.geeksforgeeks.org/problems/binary-array-sorting-1587115620/1
#include <bits/stdc++.h>
using namespace std;

void sort(vector<int> &a)
{
    int index = 0;
    
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == 0)
        {
            swap(a[i], a[index]);
            index++;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a)
        cin >> x;
    
    sort(a);
    for(int x: a)
        cout << x << " ";
    cout << "\n";
}