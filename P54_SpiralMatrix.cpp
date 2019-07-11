class Solution {
public:
    bool switch_case = 1; // 1:x軸 0:y軸
    int direction_x = 1; // 1往右 0往左
    int direction_y = 1;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m1 = matrix.size();
        if(m1 == 0) return res;
        int n1 = matrix[0].size();
        while(res.size() < m1*n1){
            int m = matrix.size();
            int n = matrix[0].size();
            cout << m << n << endl;
            if(switch_case == 1){
                switch_case = 0; 
                if(direction_x == 1){
                    for(int i = 0; i < n; i++){
                        cout << matrix[0][0] << endl;
                        res.push_back(matrix[0][0]);
                        matrix[0].erase(matrix[0].begin());
                    }
                    matrix.erase(matrix.begin());
                    direction_x = 0;
                }
                else{
                    for(int i = n - 1; i >= 0; i--){
                        cout << matrix[m-1][i] << endl;
                        res.push_back(matrix[m-1][i]);
                        matrix[m-1].erase(matrix[m-1].begin() + i);
                    }
                    matrix.erase(matrix.end());
                    direction_x = 1;
                }
            }
            else{// 0
                switch_case = 1;
                if(direction_y == 1){
                    for(int i = 0; i < m; i++){
                        cout << matrix[i][n-1] << endl;
                        res.push_back(matrix[i][n-1]);
                        matrix[i].pop_back();
                    }
                    direction_y = 0;
                }
                else{
                    for(int i = m - 1; i >= 0; i--){
                        res.push_back(matrix[i][0]);
                        matrix[i].erase(matrix[i].begin());
                    }
                    direction_y = 1;
                }
            }
        }
        return res;
    }
};
