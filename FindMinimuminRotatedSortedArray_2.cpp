/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates
*/
class Solution {
public:
    int findMin(vector<int> &num) {
        int min;
        int left = 0, right = num.size() - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(mid > 0 && num[mid] < num[mid - 1])
                return num[mid];
            if(num[left] < num[mid])
            {
                if(num[right] > num[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else if(num[left] > num[mid])
                right = mid + 1;
            else if(num[right] < num[mid])
                left = mid + 1;
            else 
                right--;
        }
        //all the elements are the same
        return num[0];
    }
};
