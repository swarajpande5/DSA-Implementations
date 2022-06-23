// Course schedule 3: https://leetcode.com/problems/course-schedule-iii/

class Solution 
{
public:
    int scheduleCourse(vector<vector<int>>& courses) 
    {
        int n = courses.size();
        int currTime = 0;
        priority_queue<int> maxHeap;
        
        // Sorting in ascending order according to lastday
        sort(courses.begin(), courses.end(), [](auto a, auto b) {
            return a[1] < b[1];
        });
        
        for(auto course: courses)
        {
            int duration = course[0];
            int lastDay = course[1];
            
            currTime += duration;
            maxHeap.push(duration);
            
            // If the current time exceed the lastday of the current course
            // we need to remove some long courses to adjust the current course
            if(currTime > lastDay)
            {
                currTime -= maxHeap.top();
                maxHeap.pop();
            }
        }
        
        return maxHeap.size();
    }
};