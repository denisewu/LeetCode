/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/

#include <algorithm>

string int2str(int i)
{
    char b[15] = {0};
    sprintf(b, "%d", i);
    return b;
}
    
bool compareNumber(int i1, int i2)
{
       string str1 = int2str(i1);
       string str2 = int2str(i2);
       return str1 + str2 > str2 + str1;
}
    
class Solution {
public:
    string largestNumber(vector<int> &num) {
        string ret;
        bool first = true;
        
        sort(num.begin(), num.end(), compareNumber);
        
        for(size_t i = 0; i < num.size(); i++)
        {
            if(!num[i] && first && i != num.size() - 1)
                continue;
            first = false;
            ret += int2str(num[i]);
        }
        return ret;
    }
    
};
