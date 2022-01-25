// Perfect peak of array: https://www.interviewbit.com/problems/perfect-peak-of-array/

int Solution::perfectPeak(vector<int> &A) 
{
    int n = A.size();
    
    // left_max array contains the value of max element to left of each element in the array
    int left_max[n] = {0};

    // right_min array contains the value of the min element to right of each element in the array 
    int right_min[n] = {0};

    left_max[0] = A[0];
    right_min[n - 1] = A[n - 1];

    for(int i = 1; i < n; i++)
        left_max[i] = max(left_max[i - 1], A[i]);
    
    for(int i = n - 2; i>= 0; i--)
        right_min[i] = min(right_min[i + 1], A[i]);

    // Lastly, we check for that element which is greater than all the elements on the left
    // and is smaller than all the elements on the right
    for(int i = 1; i < n - 1; i++)
        if(A[i] > left_max[i - 1] && A[i] < right_min[i + 1])
            return 1;
    return 0;
}