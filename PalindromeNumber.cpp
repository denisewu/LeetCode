//Determine whether an integer is a palindrome. Do this without extra space.
class Solution {
public:
    bool isPalindrome(int x) {
       if(x < 0)
            return false;
        int scale = 0;
        for(int temp = x; temp > 0; temp /= 10, scale ++);
        scale = pow(10, scale - 1);
        
        while(scale > 1)
        {
            int left = x / scale;
            int right = x % 10;
            if(left != right)
                return false;
            x = (x % scale) / 10;
            scale /= 100;
        }
        return true;
        
    }
    
};
