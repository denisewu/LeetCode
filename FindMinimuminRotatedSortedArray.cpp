/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/
class Solution {
public:
    int findMin(vector<int> &num) {
        bool found = false;
        int left = 0, right = num.size() - 1;
        int mid;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if((mid > 0 && num[mid] < num[mid - 1]))
            {
                found = true;
                break;
            }
            if(num[mid] > num[right])
                left = mid + 1;
            else if(num[mid] < num[right])
                right = mid - 1;
            else 
                break;
        }
        if (found)
            return num[mid];
        else
            return num[0];
    }
};
