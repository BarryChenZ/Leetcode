class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0) return;
        int col = matrix[0].size();
        vector<int> row_pos;
        vector<int> col_pos;
        cout << row << col << endl;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == 0){
                    row_pos.push_back(i);
                    col_pos.push_back(j);
                }
            }
        }
        
        sort(row_pos.begin(), row_pos.end());
        sort(col_pos.begin(), col_pos.end());
        cout << row_pos.size() << col_pos.size() << endl;
        if(row_pos.size() == 0) return;
        int temp = 0;
        temp = row_pos[0];
        for(int i = 0; i < row_pos.size(); i++){
            if(row_pos[i] != temp || i == 0){
                temp = row_pos[i];
                for(int j = 0; j < col; j++){
                    matrix[row_pos[i]][j] = 0;
                }
            }
        }
        temp = col_pos[0];
        for(int i = 0; i < col_pos.size(); i++){
            if(col_pos[i] != temp || i == 0){
                temp = col_pos[i];
                for(int j = 0; j < row; j++){
                    matrix[j][col_pos[i]] = 0;
                }
            }
        }
        return;
    }   
};
