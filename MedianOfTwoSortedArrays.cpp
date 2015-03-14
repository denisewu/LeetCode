
/*
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

class Solution {
    int findKth(int A[], int m, int B[], int n, int k)
    {   
        if(m > n)
            return findKth(B, n, A, m, k);
        if(m == 0)
            return B[k - 1];
        if(k == 1)
            return A[0] < B[0]? A[0] :B[0];
        int pa = min(m, k / 2);
        int pb = k - pa;
    
        if(A[pa - 1] == B[pb - 1])
            return A[pa - 1];
        else if(A[pa - 1] < B[pb - 1])
            return findKth(A + pa, m - pa, B, n, k - pa);
        else
            return findKth(A, m, B + pb, n - pb, k - pb);
    }
    
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if(total % 2 == 1)
            return findKth(A, m, B, n, total / 2 + 1);
        else
            return (findKth(A, m, B, n, total / 2)
                    + findKth(A, m, B, n, total / 2 + 1)) / 2.0;
    }
};
