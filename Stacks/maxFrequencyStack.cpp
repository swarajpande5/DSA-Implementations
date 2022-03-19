// Maximum frequency stack: https://leetcode.com/problems/maximum-frequency-stack/

class FreqStack 
{
public:
    
    int maxFreq;
    unordered_map<int, int> freq;               // To store frequency of each element
    unordered_map<int, stack<int>> freqStack;   // To store the numbers with same frequency in a stack 
    
    FreqStack() 
    {
        // Initially the maximum frequency is 0
        maxFreq = 0;
    }
    
    void push(int val) 
    {
        freq[val]++;
        
        // Updating max frequency 
        if(maxFreq < freq[val])
            maxFreq = freq[val];
        
        // Pushing val to its freq stack
        freqStack[freq[val]].push(val);
    }
    
    int pop() 
    {
        // Getting the top element from the stack of maximum frequency
        int top = freqStack[maxFreq].top();
    
        // Updating both the maps
        freqStack[maxFreq].pop();
        freq[top]--;
        
        // If the stack of maximum element become empty, then deleting it from freqStack along with decreasing maxFreq
        if(freqStack[maxFreq].empty())
        {
            freqStack.erase(maxFreq);
            maxFreq--;
        }
        
        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */