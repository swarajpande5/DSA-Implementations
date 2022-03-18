// Min cost climbing stairs: https://leetcode.com/problems/min-cost-climbing-stairs/

class RecursiveSolution
{
public:

    int minCost(vector<int> &cost, int n)
    {
        if(n < 0)
            return 0;
        
        if(n == 0 || n == 1)
            return cost[n];

        return cost[n] + min(minCost(cost, n - 1), minCost(n - 2))
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        return min(minCost(cost, n - 1), minCost(cost, n - 2));
    }
};

// Bottom up DP
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        for (int i = 2; i < cost.size(); i++)
            cost[i] += min(cost[i - 1], cost[i - 2]);

        return min(cost[cost.size() - 1], cost[cost.size() - 2]);
    }
};