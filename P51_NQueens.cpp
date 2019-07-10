class Solution {
public:
    int counter = 0;
    int k = 0;
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res(1000);
        int col[n];
        int row[n];
        for(int i = 0; i < n; i++){
            col[i] = 0;
            row[i] = 0;
        }
        input(res, col, row, n);
        res.resize(counter);
        return res;
    }
    void input(vector<vector<string>>& res, int* col, int* row, int n){
        if(k == n){
            vector<string> tmp(n, string(n, '.'));
            for(int i = 0; i < n; ++i){
                cout << i << col[i] << endl;
                tmp[i][col[i]] = 'Q';
                res[counter].push_back(tmp[i]);
            }
            counter++;
            return;
        }
        for(int i = 0; i < n; i++){
                bool ok = 1;
                for(int x = 0; x < k; x++){
                    float x_slope = col[x] - i;
                    float y_slope = row[x] - k;
                    float slope = 0;
                    if(x_slope == 0) slope = 0;
                    else slope = y_slope / x_slope;
                    if(slope == 0 || slope == 1 || slope == -1 || slope == 1/2 || slope == -1/2){
                        ok = 0;
                        break;
                    }
                }
                if(ok == 1) {
                    col[k] = i;
                    row[k] = k;
                    k++;
                    input(res , col, row, n);
                    k--;
                }
        }
    }
};
