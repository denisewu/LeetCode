class Solution {
public:
    int sqrt(int x) {
       
        if(x == 0)
            return x;
        double curr = 1, prev;
        do{
            prev = curr;
            curr = ((x / prev) / 2 + prev / 2);
        }while(abs(curr - prev) > 0.0001);
        return (int)curr;
    }
};
