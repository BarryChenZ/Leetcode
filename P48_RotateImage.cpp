class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        cout << row << col << endl;
        int k = 0;
        for(int i = row - 1; i >= 0; i--){
            k = 0;
            for(int j = 0; j < col; j++){
                int temp = matrix[i][0];
                cout << temp << endl;
                matrix[i].erase(matrix[i].begin());
                matrix[k].push_back(temp);
                k++;
            }
        }
    }
};
