// Maximum profit in job scheduling: https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/

class Solution {
public:

    struct Job {
        int start;
        int end;
        int profit; 
    };

    static int comparator(Job a, Job b) {
        return a.end < b.end;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<Job> job(n); 
        vector<int> dp(n); 

        for(int i = 0; i < n; i++) {
            job[i].start = startTime[i];
            job[i].end = endTime[i]; 
            job[i].profit = profit[i];
        }

        sort(job.begin(), job.end(), comparator); 

        dp[0] = job[0].profit;

        for(int i = 1; i < n; i++) {
            int f = 0; 
            for(int j = i - 1; j >= 0; j--) {
                if(job[j].end <= job[i].start) {
                    f = dp[j];
                    break;
                }
            }

            dp[i] = max(dp[i - 1], f + job[i].profit);
        }

        return dp[n - 1];
    }
};
