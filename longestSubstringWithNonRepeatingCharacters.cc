class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> character_map(26);
        vector<int> character_index(26);
        character_map={0};
        character_index={-1};
        if (s.empty())
            return 0;
        int maxLength=0,length=0;
        for (int i =0;i<s.length();i++)
        {
            if (character_map[s[i]-'a']==1)
            {
                for(int j=i-length;j<=character_index[s[i]-'a'];j++)
                {
                    character_map[s[j]-'a']=0;
                                        
                }  
                length-=(character_index[s[i]-'a']-i+length+1);
                
            }
            length++;
            if (length>maxLength)
                maxLength=length;
            character_map[s[i]-'a']=1;
            character_index[s[i]-'a']=i;
        }
        return maxLength;
    }
};