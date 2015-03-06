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
  
 
    vector<string> letterCombinationsAux(string digits) {
        vector<string> ret;
        if(digits.empty())
            return ret;
            
        ret = letterCombinationsAux(digits.substr(0, digits.length() - 1));
        if(ret.empty())
            ret.push_back("");
            
        string mapped = dict[digits[digits.length() - 1] - '2'];
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
         return ret;
    }
    
    vector<string> letterCombinations(string digits)
    {
       // return letterCombinationsIter(digits);
       return letterCombinationsAux(digits);
    }
}
