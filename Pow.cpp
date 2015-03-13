//Implement pow(x, n).
class Solution {
public:
    double pow(double x, int n) {
        unsigned nt = n < 0 ? -n: n;
        double result = 1;
        while(nt)
        {
            if(nt & 0x1)
                result *= x;
            x *= x;
            nt >>= 1;
        }
        if(n < 0)
            return 1 / result;
        return result;
    }
};
