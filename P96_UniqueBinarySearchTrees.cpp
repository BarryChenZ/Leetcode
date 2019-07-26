class Solution {
public:
    int numTrees(int n) {
        if(n==0) return 1;
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int> v(n + 1,1);
        v[0] = 1;
        v[1] = 1; 
        v[2] = 2;
        for(int i = 3;i <= n; i++){
            v[i] = 0;
            for(int j = 1;j <= i; j++){
                v[i] += v[j - 1] * v[i - j];
            }
        }
        return v[n];
    }
};
