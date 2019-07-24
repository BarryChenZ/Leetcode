//參考
class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0) return {0};
        vector<int> res;
        int num = 0;
        gray(res, n, 0, num);
        return res;
    }
    void gray(vector<int>& res, int n, int i, int &num){
        if(i == n){
            res.push_back(num);
            return;
        }
        gray(res, n, i+1, num);
        num  ^= (1 << i);
        gray(res, n, i+1, num);
    }
    
};
