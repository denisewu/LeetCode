/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

class Solution {
public:
    int reverse(int x) {
       int negative = x < 0 ? -1: 1;
       int result = 0;
       int temp = x * negative;
       while(temp > 0)
       {
           if(result > INT_MAX / 10)
                return 0;
           result = result * 10 + temp % 10;
           temp = temp / 10;
       }
       return result * negative;
    }
};
