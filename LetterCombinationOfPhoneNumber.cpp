/*
Given a digit string, return all possible letter combinations that the number could represent.
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
class Solution {
    vector<string> dict = 
        { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ret;
        
        ret.push_back("");
        
        for(int i = 0; i < digits.length(); i++)
        {
            
            string mapped = dict[digits[i] - '0' - 2];
           
                int len = ret.size();
                for(int j = 0; j < len; j++)
                {
                    string prefix = ret[0];
                    ret.erase(ret.begin());
                    for(int k = 0; k < mapped.length(); k++)
                    {   
                        string str = prefix + mapped[k];
                        ret.push_back(str);
                    }
                }
            
        }
        return ret;
    }
    
    vector<string> letterCombinationsRecursive(string digits) {
        vector<string> ret;
        if(digits.length() == 0)
        {
            ret.push_back("");
            return ret;
        }
      
        vector<string> strs = letterCombinations(digits.substr(0, digits.length() - 1));
        char lastChar = digits[digits.length() - 1];
        string lastMapping = dict[lastChar - '0' - 2];
        for(int i = 0; i < lastMapping.length(); i++)
        {
          
                for(int j = 0; j < strs.size(); j++)
                {
                    string s = strs[j] + lastMapping[i];
                    ret.push_back(s);
                }

            
        }
        return ret;
 
    }
}
