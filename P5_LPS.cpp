class Solution {
public:
    string longestPalindrome(string s) {
        
        char s_1[s.size() * 2 + 1];      
        int z[s.size() * 2 + 1], L, R;  

 
        int N = s.size();
    
        memset(s_1, '.', N*2+1);
        
        for (int i = 0; i < N; ++i) {
            s_1[i*2+1] = s[i];
        }
            
        N = N * 2 + 1;
 
    // Manacher's Algorithm
        z[0] = 1;
        L = R = 0;
        for (int i = 1; i < N; ++i)
        {
            int ii = L - (i - L);   
            int n = R + 1 - i;
            if (i > R)
            {
                int j = 0;
                while (i-j >= 0 && i+j < N && s_1[i-j] == s_1[i+j]) ++j;
                z[i] = j;
                L = i;
                R = i + z[i] - 1;
            }
            else if (z[ii] == n)
            {
                int j = 0;
                while(i-n-j >= 0 && i+n+j < N && s_1[i-n-j] == s_1[i+n+j]) j++;
                z[i] = n + j;
                L = i;
                R = i + z[i] - 1;
            }
            else
            {
                z[i] = min(z[ii], n);
            }
             //cout << z[i] << endl;
        }
 
    
        int n = 0, p = 0;
        for (int i = 0; i < N; ++i)
            if (z[i] > n)
                n = z[p = i];
 
    
    string result;
    
    for (int i = p - z[p] + 1; i <= p + z[p] - 1; ++i)
        if (i & 1){
            result += s_1[i];
        }
    return result;
    }
};
