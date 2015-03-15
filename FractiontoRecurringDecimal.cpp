/*Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
*/
class Solution {

public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";
        string ret;
        if((numerator < 0 ) ^ (denominator < 0))
            ret += "-";
        
        long int n = abs((long int)numerator);
        long int d = abs((long int)denominator);
        ret += to_string(n / d);
        long int r = n % d;
        if(r == 0)
            return ret;
        else
            ret += '.';
        unordered_map<int, int> map;
        while(r)
        {
            if(map.find(r) != map.end())
            {
                ret.insert(map[r], 1, '(');
                ret += ')';
                break;
            }
            map[r] = ret.size();
            r *= 10;
            ret += to_string(r / d);
            r = r % d;
        }
        return ret;
    }
};
