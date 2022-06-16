// Min cost climbing stairs: https://leetcode.com/problems/min-cost-climbing-stairs/
// https://leetcode.com/problems/min-cost-climbing-stairs/discuss/476388/4-ways-or-Step-by-step-from-Recursion-greater-top-down-DP-greater-bottom-up-DP-greater-fine-tuning

class RecursiveSolution
{
public:

    int minCost(vector<int> &cost, int n)
    {
        if(n < 0)
            return 0;
        
        if(n == 0 || n == 1)
            return cost[n];

        return cost[n] + min(minCost(cost, n - 1), minCost(cost, n - 2))
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        return min(minCost(cost, n - 1), minCost(cost, n - 2));
    }
};

// Space Optimized Bottom up DP 
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();

        int first = cost[0];
        int second = cost[1];

        if(n <= 2)
            return min(first, second);

        for(int i = 2; i < n; i++)
        {
            int curr = cost[i] + min(first, second);
            
            first = second;
            second = curr;
        }

        return min(first, second);
    }
};