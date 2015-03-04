/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

class Solution {
    void generateParenthesisAux(int left, int right, string curr, vector<string>& ret)
    {
        if(left == 0 && right == 0)
        {
            ret.push_back(curr);
            return;
        }
        if(left == right)
        {
            generateParenthesisAux(left - 1, right, curr + "(", ret);
            return;
        }
        //left < right
        if(left > 0)
        {
            generateParenthesisAux(left - 1, right, curr + "(", ret);
        }
        
        generateParenthesisAux(left, right - 1, curr + ")", ret);
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        generateParenthesisAux(n, n, "", ret);
        return ret;
    }
};
