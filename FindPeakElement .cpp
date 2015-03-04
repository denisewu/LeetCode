/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        
        size_t left = 0, right = num.size() - 1;
        while(left <= right)
        {
            int leftSmaller = false, rightSmaller = false;
            size_t mid = (left + right) / 2;
            if(mid == 0 || num[mid] > num[mid - 1])
                leftSmaller = true;
            
            if(mid == num.size() - 1 || num[mid] > num[mid + 1])
                rightSmaller = true;
            
            if(leftSmaller &&  rightSmaller)
                return mid;
            
            if(!rightSmaller)
                left = mid + 1;
                
            else if(!leftSmaller)
                right = mid - 1;
        }
    }
};
