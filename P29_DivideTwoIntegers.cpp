class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == -1*pow(2,31) && divisor == -1){
            return pow(2,31)-1;
        }
        else{
            return dividend/divisor;
        }
    }
};
