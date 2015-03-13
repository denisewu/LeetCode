/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
*/

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ret;
        
        for(int i = 0; i < words.size();)
        {
            int len = words[i].length();
            int j = i + 1;
            for(; j < words.size() && len + words[j].length() < L; j++)
                len += (1 + words[j].length());
            
            string line;
            
            if(j == words.size())
            {
                for(int k = i; k < j; k++)
                {
                    if(k == i)
                        line += words[k];
                    else
                        line += (" " + words[k]);
                }
                line.append(L - line.length(), ' ');
                ret.push_back(line);
                return ret;
            }
            if(j - i == 1)
            {
                line += words[i];
                line.append(L - line.length(), ' ');
                ret.push_back(line);
                i++;
                continue;
            }
            
            int wordlen = 0;
            for(int k = i; k < j; k++)
                wordlen += words[k].length();
            int blanklen1 = (L - wordlen) / (j - i - 1);
            int blanklen2 = (L - wordlen) % (j - i - 1);
            for(int k = i; k < j; k++)
            {
                if(k == i)
                    line += words[k];
                else
                {
                    line.append(blanklen1, ' ');
                    if(blanklen2)
                    {
                        line.append(1, ' ');
                        blanklen2--;
                    }
                    line += words[k];
                }
             }
             ret.push_back(line);
            i = j;
        }
        return ret;
    }
};
