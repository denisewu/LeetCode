/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int len1 = version1.length();
        int len2 = version2.length();
        while(i < len1 && j < len2)
        {
            int k1 = i, k2 = j;
            while(k1 < len1 && version1[k1] != '.') 
                k1++;
            while(k2 < len2 && version2[k2] != '.' )
                k2++;
            int num1 = atoi(version1.substr(i, k1 - i ).c_str());
            int num2 = atoi(version2.substr(j, k2 - j).c_str());
            
            if(num1 > num2)
                return 1;
            else if(num1 < num2)
                return -1;
            i = k1 + 1;
            j = k2 + 1;
        }
        string left;
        bool minus = false;
        if(i < len1)
            left = version1.substr(i, len1 - i);
        else if(j < len2)
        {
            minus = true;
            left = version2.substr(j, len2 - j);
        }
        else 
            return 0;
        i = 0;
        while(i < (int)left.length())
        {
            int k = i;
            while(k < (int)left.length() && left[k] != '.')
                k++;
            int num = atoi(left.substr(i, k - i).c_str());
            if(num != 0)
                return minus? -1 : 1;
            i = k + 1;
        }
        return 0;
        
    }
};
