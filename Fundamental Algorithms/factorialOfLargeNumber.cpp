// Factorial of a Large number : https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1
#include <bits/stdc++.h>
using namespace std;

void multiply(int n, vector<int> &res)
{
    int carry = 0;

    for(int i = 0; i < res.size(); i++)
    {
        int num = n * res[i];
        res[i] = (num + carry) % 10;
        carry = (num + carry) / 10;
    }

    while(carry)
    {
        res.push_back(carry % 10);
        carry /= 10;
    }
}

vector<int> factorial(int n)
{
    vector<int> res;
    res.push_back(1);

    for(int i = 2; i <= n; i++)
        multiply(i, res);

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> res = factorial(n);

    for(auto ele: res)
        cout << ele;
    cout << "\n";

    return 0;
}