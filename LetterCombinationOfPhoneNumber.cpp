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
 ic:
    vector<string> letterCombinationsIter(string digits)
    {
       vector<string> ret;
       if(digits.empty())
            return ret;
            
       ret.push_back("");
       for(int i = 0; i < digits.length(); i++)
       {
           string mapped = dict[digits[i] - '2'];
           int len = ret.size();
           for(int i = 0; i < len; i++)
           {
               string prefix = ret[i];
               for(int j = 0; j < mapped.length(); j++)
               {
                   string t = prefix;
                   t.append(1, mapped[j]);
                   ret.push_back(t);
               }
           }
           ret.erase(ret.begin(), ret.begin() + len);
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
    vector<string> letterCombinations(string digits)
    {
       // return letterCombinationsIter(digits);
       return letterCombinationRecursive(digits);
    }
    
   
}
