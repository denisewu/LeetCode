/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/
class Solution {
public:
    int maxProduct(int A[], int n) {
       int minProd;
       int maxProd;
       int result;
       if(n <= 0)
            return 0;
       for(int i = 0; i < n; i++)
       {
           if(i == 0)
           {
               minProd = maxProd = A[i];
               result = maxProd;
           }
           else
           {
               int minCopy = minProd;
               minProd = min(minProd * A[i],  min(A[i], A[i] * maxProd));
               maxProd = max(minCopy * A[i], max(A[i], A[i] * maxProd));
               if(max(minProd, maxProd) > result)
                    result = max(minProd, maxProd);
           }
       }
       return result;
        
    }
};
