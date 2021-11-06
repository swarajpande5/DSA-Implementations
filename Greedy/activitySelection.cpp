// Activity selection : https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if(a.first.second != b.first.second)
        return a.first.second < b.first.second;
    
    return a.second < b.second;
}

int activitySelection(vector<int> start, vector<int> end, int n)
{
    // first.first = start time 
    // first.second = end time
    // second = index
    vector<pair<pair<int, int>, int>> activity;    

    
    for(int i = 0; i < n; i++)
        activity.push_back({{start[i], end[i]}, i + 1});
    
    sort(activity.begin(), activity.end(), compare);

    // The first activity is always selected hence count is initialized to 1.
    int i = 0;
    int count = 1;

    for(int j = 1; j < n; j++)
    {
        // If current activity start time is greater than or equal 
        // to the finish time of previous one, then select it
        if(activity[j].first.first > activity[i].first.second)
        {
            count++;

            // now the finish time becomes the start time of the new activity
            i = j;
        }
    }

    return count;
}   

int main()
{
    int n; 
    cin >> n;
    vector<int> start(n), end(n);
    for(int &x: start)
        cin >> x;
    for(int &x: end)
        cin >> x;
    
    cout << activitySelection(start, end, n) << "\n";

    return 0;
}