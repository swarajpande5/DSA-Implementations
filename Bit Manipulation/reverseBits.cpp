// Reverse the bits of an 32-bit unsigned integer
#include <bits/stdc++.h>
using namespace std;

unsigned int reverseBits(int n)
{
    bitset<32> b(n);
    bitset<32> rev;

    for(int i = 0, k = 31; i < 32; i++, k--)
        rev[k] = b[i];
    
    return (unsigned int)rev.to_ulong();
}

int main()
{
    int n; 
    cout << "Enter number: ";
    cin >> n;

    cout << reverseBits(n) << endl;
}