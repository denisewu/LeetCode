/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?
Related problem: Reverse Words in a String II
*/
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if(n <= 0 || k < 1)
            return;
        k = k % n;
        int pos = 0;
        int valToMove = nums[pos];
        int count = 0;
        int start = pos;
        while(count < n)
        {
            do
            {
                int targetPos = (pos + k) % n;
                int temp = nums[targetPos];
                nums[targetPos] = valToMove;
                valToMove = temp;
                pos = targetPos;
                count++;
            }while(pos != start);
            
            start++;
            pos = start;
            valToMove = nums[pos];
        }
    }
};
