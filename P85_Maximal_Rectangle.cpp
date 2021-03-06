class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = m == 0 ? 0 : matrix[0].size();
        if (m == 0 || n == 0) return 0;
        vector<int> v(n, 0);
        int res = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    v[j]++;
                } else {
                    v[j] = 0;
                }
            }
            res = max(res, maximalRectangle(v));
            
        }
        
        return res;
    }
    
    int maximalRectangle(vector<int> v) {
        stack<int> s;
        int i = 0, cnt = 0, res = 0;
        
        while (i  < v.size()) {
            if (s.empty() || v[i] >= s.top()) {
                //cout << i;
                while (cnt) {
                    s.push(v[i]);
                    cnt--;
                }
                s.push(v[i++]);
            } 
            else {
                cout << i;
                cnt++;
                int val = s.top();
                cout<< val << endl;
                s.pop();
                res = max(res, val * cnt);
            }
        }
        
        cnt = 1;
        while (!s.empty()) {
            int val = s.top();
            s.pop();
            res = max(res, val * cnt);
            cnt++;
        }
        return res;
    }
};
