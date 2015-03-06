/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/


class Solution {
      
public:
    string getPermutation(int n, int k) {
                // create a factorial map
        string ret;
        vector<int> numbers(n);
        int product = 1;
        for(int i = 0; i < n; i++)
        {
            numbers[i] = i + 1;
            product *= (i + 1);
        }
        k = k - 1;
        product /= n;
        
        for(int i = 0; i < n - 1; i++)
        {
            int select = (k / product) ;
            ret.append(1, '0' + numbers[select]);
            numbers.erase(numbers.begin() + select);
            k = k % product;
            product /= (n - i - 1);
        }

        ret.append(1, '0' + numbers[0]);
        return ret;
    }
};
