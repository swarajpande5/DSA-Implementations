// Program to inplace merge two sorted arrays
#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> a, vector<int> b)
{
    vector<int> res;
    int i, j;

    i = j = 0;
    while(i < a.size() && j < b.size())
    {
        if(a[i] < b[j])
        {
            res.push_back(a[i]);
            i++;
        }
        else 
        {
            res.push_back(b[j]);
            j++;
        }
    }

    while(i < a.size())
    {
        res.push_back(a[i]);
        i++;
    }

    while(j < b.size())
    {
        res.push_back(b[j]);
        j++;
    }

    return res;
}

int main()
{
    vector<int> a, b, res;
    int m, n, ele;

    cout << "Enter sizes of the arrays: ";
    cin >> m >> n;

    cout << "Enter first array: ";
    for(int i = 0; i < m; i++)
    {
        cin >> ele;
        a.push_back(ele);
    }

    cout << "Enter second array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> ele;
        b.push_back(ele);
    }

    cout << "After merging: ";
    res = merge(a, b);

    for(int i = 0; i < m + n; i++)
        cout << res[i] << " ";
    cout << "\n";

    return 0;
}
