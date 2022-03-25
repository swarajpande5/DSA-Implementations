// Cycle Sort

#include <bits/stdc++.h>
using namespace std;

void cycleSort(int a[], int n)
{
    int start, element, pos, temp, i;

    /*Loop to traverse the array elements and place them on the correct position*/
    for (start = 0; start <= n - 2; start++)
    {
        element = a[start];

        /*position to place the element*/
        pos = start;

        for (i = start + 1; i < n; i++)
            if (a[i] < element)
                pos++;
        if (pos == start) /*if the element is at exact position*/
            continue;
        while (element == a[pos])
            pos += 1;
        if (pos != start) /*put element at its exact position*/
        {
            // swap(element, a[pos]);
            temp = element;
            element = a[pos];
            a[pos] = temp;
        }
        /*Rotate rest of the elements*/
        while (pos != start)
        {
            pos = start;
            /*find position to put the element*/
            for (i = start + 1; i < n; i++)
                if (a[i] < element)
                    pos += 1;

            /*Ignore duplicate elements*/
            while (element == a[pos])
                pos += 1;

            /*put element to its correct position*/
            if (element != a[pos])
            {
                temp = element;
                element = a[pos];
                a[pos] = temp;
            }
        }
    }
}

void print(int a[], int n) 
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = {89, 44, 29, 19, 9, 39, 59, 49, 4, 1};
    int n = sizeof(a) / sizeof(a[0]);
    print(a, n);
    cycleSort(a, n);
    print(a, n);
    return 0;
}