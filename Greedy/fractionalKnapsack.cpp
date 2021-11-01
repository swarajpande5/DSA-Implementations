// Fractional Knapsack : https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
#include <bits/stdc++.h>
using namespace std;

typedef struct Item 
{
    int value;
    int weight;
}Item;

// Comparator function to sort items according to value/weight ratio in descending order
bool compare(Item a, Item b)
{
    double r1 = (double) a.value / a.weight;
    double r2 = (double) b.value / b.weight;

    return r1 > r2;
}

// Function to calculate maximum total value possible in knapsack
double fractionalKnapsack(Item arr[], int W, int n)
{
    sort(arr, arr + n, compare);

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(W >= arr[i].weight)
        {
            ans += arr[i].value;
            W -= arr[i].weight;
        }
        else 
        {
            double r = (double) arr[i].value / arr[i].weight;
            ans += r * W;
            W = 0;
            break;
        }
    }

    return ans;
}

int main()
{
    int n; 
    cin >> n;

    Item arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i].value >> arr[i].weight;
    
    int W;
    cin >> W;

    cout << fractionalKnapsack(arr, W, n) << "\n";

    return 0;
}