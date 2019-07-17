//Fibonacci Sequence
class Solution {
public:
    int climbStairs(int n) {
        int base0 = 0;
        int base1 = 1;
        int res = 0;
        for (int i = 0; i < n; i++){
            res = base0 + base1;
            base0 = base1;
            base1 = res;
        }
        return res;
    }
};
