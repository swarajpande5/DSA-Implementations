// kth Symbol in grammar: https://leetcode.com/problems/k-th-symbol-in-grammar/

class Solution 
{
public:
    int kthGrammar(int n, int k) 
    {
        if(n == 1 || k == 1)
            return 0;
        
        int len = pow(2, n - 2);
        if (k <= len)
            return kthGrammar(n - 1, k);
        
        return !kthGrammar(n - 1, k - len);
    }
};