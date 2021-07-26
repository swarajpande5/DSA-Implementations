// Sort an array of 0s, 1s and 2s
#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int> &a)
{
    int low = 0, mid = 0, high = a.size() - 1;

    while(mid <= high)
    {
        if(a[mid] == 0)
        {
            swap(a[mid], a[low]);
            mid++;
            low++;
        }
        
        if(a[mid] == 1)
            mid++;
        
        if(a[mid] == 2)
        {
            swap(a[mid], a[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> a = {0, 1, 2, 1, 1, 0, 2, 1, 2, 2, 0, 1, 1, 2};

    for(int e: a)
        cout << e << " ";
    cout << "\n";

    sort012(a);

    for(int e: a)
        cout << e << " ";
    cout << "\n";

    return 0;
}
