class Solution {
public:
    int input = 1;
    int behavior = 0;
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int min_row = 0;
        int min_col = 0;
        int max_row = n - 1;
        int max_col = n - 1;
        while(input != n*n + 1){
            switch(behavior){
                case 0:
                    for(int i = min_col; i <= max_col; i++){
                        res[min_row][i] = input;
                        input ++;
                    }
                    min_row++;
                    behavior = 1;
                    break;
                case 1:
                    for(int j = min_row; j <= max_row; j++){
                        res[j][max_col] = input;
                        input ++;
                    }
                    max_col--;
                    behavior = 2;
                    break;
                case 2:
                    for(int i = max_col; i >= min_col; i--){
                        res[max_row][i] = input;
                        input ++;
                    }
                    max_row--;
                    behavior = 3;
                    break;
                case 3:
                    for(int j = max_row; j >= min_row; j--){
                        res[j][min_col] = input;
                        input ++;
                    }
                    min_col++;
                    behavior = 0;
                    break;    
            }
        }
        return res;
    }
};
