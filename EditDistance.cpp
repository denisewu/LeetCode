/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> book(word2.length() + 1);
        for(int i = 0; i < word2.length() + 1; i++)
            book[i] = i;
        int topleft = book[0];
        for(int i = 1; i < word1.length() + 1; i++)
            for(int j = 0; j < word2.length() + 1; j++)
            {
                if(j == 0)
                {
                    topleft = book[j];
                    book[j] = i;
                }
                else
                {   
                    if(word1[i - 1] == word2[j - 1])
                    {
                        int t = book[j];
                        book[j] = topleft;
                        topleft = t;
                    }
                    else
                    {
                        int t = book[j];
                        book[j] = min(min(topleft, book[j]), book[j - 1]) + 1;
                        topleft = t;
                    }
                }
            }
        return book[word2.length()];
    }
};
