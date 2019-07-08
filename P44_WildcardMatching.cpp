class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        if(n1 == 0 && n2 == 0) return 1;
        if(s.empty()) return p.empty() || p.find_first_not_of('*') == string::npos;
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, false));
        dp[0][0] = true;
        if(p[0] == '*'){
            for(int i = 1; i <= n1; i++){
                dp[i][0] = true;
            }
            for(int j = 1; j <= n2; j++){
                dp[0][j] = dp[0][j-1] && p[j-1] == '*';
            }
        }
        
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(p[j-1] != '*'){
                    dp[i][j] = dp[i-1][j-1] && (p[j-1] == '?' || s[i-1] == p[j-1]);
                }
                else{
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];         
                }
            }
        }
        return dp[n1][n2];
    }
};
