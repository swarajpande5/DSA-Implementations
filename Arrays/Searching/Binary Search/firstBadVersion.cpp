// First Bad Version: https://leetcode.com/problems/first-bad-version/
// https://leetcode.com/problems/first-bad-version/discuss/769685/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems.

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution 
{
public:
    int firstBadVersion(int n) 
    {
        int lo = 1;
        int hi = n;
        while(lo < hi)
        {
            int mi = lo + (hi - lo) / 2;
            if(isBadVersion(mi))
                hi = mi;
            else 
                lo = mi + 1;
        }
        
        return lo;
    }
};