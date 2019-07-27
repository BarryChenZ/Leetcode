class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size()) return false;
        if (s1.size() == 0) return s2 == s3;
        if (s2.size() == 0) return s1 == s3;
        
        int m = s1.size();
        int n = s2.size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); 
        
        dp[0][0] = 1;
        
        for(int i = 1; i <= m; i++){
            dp[i][0] = s1[i - 1] == s3[i - 1] && dp[i - 1][0] == 1;
        }
        for(int i = 1; i <= n; i++){
            dp[0][i] = s2[i - 1] == s3[i - 1] && dp[0][i - 1] == 1;
        }
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[j + i - 1] || dp[i - 1][j] && s1[i - 1] == s3[j + i - 1];
            }
        }
        return dp[m][n];
    }
};
