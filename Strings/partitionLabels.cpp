// Partition labels:    https://leetcode.com/problems/partition-labels/
//                      https://leetcode.com/problems/partition-labels/discuss/899214/2-solutions-(explanation-%2B-picture)

/*
    In the first pass, we use map to store the endpoints of ranges for all characters in string.
    In the second pass, we use running maximum to store the largest endpoint of the characters in the current 
    parition segment. Let j be the previous partition checkpoint and i be the current index. As soon as running maximum
    equals current index i, we hit the new partition checkpoint. We simply push_back (j - i) into the output, set j to i 
    and proceed.
*/

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int mp[256] = {0};
        vector<int> res;

        for(int i = 0; i < s.size(); i++)
            mp[s[i]] = i;
        
        int i = 0;
        int j = -1;
        int mx = 0;

        while(i < s.size())
        {
            mx = max(mx, mp[s[i]]);

            if(mx == i)
            {    
                res.push_back(i - j);
                j = i;
            }

            i++;
        }

        return res;
    }
};