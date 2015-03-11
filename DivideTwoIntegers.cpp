/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
      
        if(divisor == 0)
            return INT_MAX;
            
        bool isNeg = false;
        if((dividend < 0 && divisor > 0 )||
            (dividend > 0 && divisor < 0))
            isNeg = true;
        
        int ret = 0;
        if(dividend == INT_MIN)
        {
            dividend += abs(divisor);
            if(divisor == -1)
                return INT_MAX;
            ret++;
        }
        if(divisor == INT_MIN)
            return ret;
        
        dividend = abs(dividend);
        divisor = abs(divisor);
        int digit = 0;
        while(divisor <= (dividend >> 1))
        {
            divisor <<= 1;
            digit++;
        }
       
        while(digit >= 0)
        {
            if(dividend >= divisor)
            {
                ret += (1 << digit);
                dividend -= divisor;
            }
            digit--;
            divisor >>= 1;
        }
        return isNeg? 0 - ret: ret;
    }
};
