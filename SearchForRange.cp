/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret;
        int left = -1, right = -1;
        int l = 0, r = n - 1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(A[mid] == target)
            {
                if(mid == 0 || (A[mid - 1] < target))
                {
                //found
                    left = mid;
                    break;
                }
                r= mid - 1;
            }
            else if(A[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        if(left != -1)
        {
            l = left;
            r = n - 1;
            while(l <= r)
            {
                 int mid = (l + r) / 2;
                 if(A[mid] == target)
                 {
                    if(mid == n - 1 || (A[mid + 1] > target))
                    {
                    //found
                        right = mid;
                        break;
                    }
                    l = mid + 1;
                }
                else if(A[mid] < target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        ret.push_back(left);
        ret.push_back(right);
        return ret;
        
    }
};
