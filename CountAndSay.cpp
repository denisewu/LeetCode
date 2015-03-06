class Solution {
public:
    string countAndSay(int n) {
        string str;
        if(n < 1)
            return str;
            
        for(int i = 0; i < n; i++)
        {
            if(i == 0)
            {
                str = "1";
                continue;
            }
            
            int count = 0;
            string nextstr;
            int pos = 0;
            while(pos < str.length())
            {
                char a = str[pos];
                if(pos > 0 && a != str[pos - 1])
                {   
                    nextstr.append(1, '0' + count);
                    nextstr.append(1, str[pos - 1]);
                    count = 1;
                }
                else
                    count++;
                pos++;
            }
            nextstr.append(1, '0' + count);
            nextstr.append(1, str[pos - 1]);
            str = nextstr;
        }
        
        return str;
    }
    
};
