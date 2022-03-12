// Find median from data stream:    https://leetcode.com/problems/find-median-from-data-stream/
//                                  https://leetcode.com/problems/find-median-from-data-stream/discuss/1227658/C%2B%2B-or-Explained-in-Detail-or-Heaps-or-Priority-Queue-or-O(logN)

class MedianFinder
{
public:

    // Max heap to store the smaller half elements
    priority_queue<int> maxHeap;

    // Min heap to store the greater half elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Variable which will contain the median value at all instance of time
    double median;

    MedianFinder()
    {
        median = 0;
    }
    

    void addNum(int num)
    {
        // Case 1: Left side heap has more elements 
        // Pushing an element would have EVEN number of elements in total,
        // so median is average of top of min and max heaps 
        if(maxHeap.size() > minHeap.size())
        {
            if(num < median)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
            else 
                minHeap.push(num);
            
            median = (double)(minHeap.top() + maxHeap.top()) / 2.0;
        }

        // Case 2: Right side heap has more elements 
        // Pushing an element would have Even number of elements in total,
        // so median is average of top of min and max heaps 
        else if(maxHeap.size() < minHeap.size())
        {
            if(num > median)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
            else 
                maxHeap.push(num);
            
            median = (double)(minHeap.top() + maxHeap.top()) / 2.0;
        }

        // Case 3: Both heaps have equal elements and are balanced.
        // If both the heaps have equal elements, then inserting this element 
        // would make the heaps have ODD number of elements and thus the median 
        // now would be only one number and not the average.
        else 
        {
            if(num < median)
            {
                maxHeap.push(num);
                median = (double)maxHeap.top();
            }
            else 
            {
                minHeap.push(num);
                median = (double)minHeap.top();
            }
        }
    }
        double findMedian()
        {
            return median;
        }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */