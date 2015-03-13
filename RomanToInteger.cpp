class Solution {
     inline int romanCharToInt(char c) {
            switch (c) {
                case 'I':   return 1;
                case 'V':   return 5;
                case 'X':   return 10;
                case 'L':   return 50;
                case 'C':   return 100;
                case 'D':   return 500;
                case 'M':   return 1000;
                default:    return 0;
            }
        }
public:
    int romanToInt(string s) {
        /*
        map<char,int> m;  
        m['I'] = 1;  
        m['V'] = 5;  
        m['X'] = 10;  
        m['L'] = 50;  
        m['C'] = 100;  
        m['D'] = 500;  
        m['M'] = 1000;
        */
        int sum = 0;
        for(int i = ((int)s.length() - 1); i >= 0; i--)
        {
            if(i + 1 == (int)s.length())
                sum += romanCharToInt(s[i]);
                
            else
            {
                int t = romanCharToInt(s[i]);
                if(t < romanCharToInt(s[i + 1]))
                {
                    sum -= t;
                }
                else
                    sum += t;
            }
        }
        return sum;
    }
};
