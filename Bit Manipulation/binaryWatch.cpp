// Binary Watch: https://leetcode.com/problems/binary-watch/

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        // Hours iterate from 0 - 11 and minutes iterate from 0 - 59
        // number of 1's match with value of turned on for any given time, then we simply output that time.
        vector<string> ans;
        for(int h = 0; h < 12; h++)
        {
            for(int m = 0; m < 60; m++)
            {
                if(__builtin_popcountll(h) + __builtin_popcountll(m) == turnedOn)
                {
                    string hour, minute;
                    hour = to_string(h);
                    if(m < 10)
                        minute = "0" + to_string(m);
                    else 
                        minute = to_string(m);
                    ans.push_back(hour+":"+minute);
                }
            }
        }
        return ans;
        
    }
};