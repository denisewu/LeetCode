/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
  */
class Solution {
    bool isOperation(string str)
    {
        if(str.length() > 1)
            return false;
        char c = str[0];
        if(c == '+' || c == '-' || c == '*' || c == '/')
            return true;
        else
            return false;
    }
    
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> operands;
        for(int i = 0; i < tokens.size(); i++)
        {
            string str = tokens[i];
            if(isOperation(str))
            {
                int right = operands.top();
                operands.pop();
                int left = operands.top();
                operands.pop();
                int rlt = 0;
                switch(str[0])
                {
                    case '+':
                        rlt = left + right;
                        break;
                    case '-':
                        rlt = left - right;
                        break;
                    case '*':
                        rlt = left * right;
                        break;
                    case '/':
                        rlt = left / right;
                        break;
                }
                operands.push(rlt);
            }
            else
                operands.push(atoi(str.c_str()));
        }
        return operands.top();
    }
};
