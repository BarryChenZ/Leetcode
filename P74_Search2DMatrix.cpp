class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool res = 0;
        int row = matrix.size();
        if(row == 0) return res;
        int col = matrix[0].size();
        if(col == 0) return res;
        int i = 0;
        int j = 0;
        while(i < row){
            if(matrix[i][j] == target) return 1;
            if(matrix[i][j] > target) break;
            j++;
            if(j == col){
                j = 0;
                i++;
            }
        }
        return res;
    }
};
