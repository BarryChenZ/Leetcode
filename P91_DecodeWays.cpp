class Solution {
public:
    int res = 0;
    int numDecodings(string s) {
        if(!s.size()) return 0;
        int n = s.size();
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] != '0';
        for(int i = 2; i <= n; i++){
            if(s[i - 2] == '1' ||
               s[i - 2] == '2' && s[i - 1] <= '6') dp[i] = dp[i-2];
            if(s[i - 1] != '0') dp[i] += dp[i - 1];
            cout << dp[i] << endl;
        }
        return dp[n];
    }
};
