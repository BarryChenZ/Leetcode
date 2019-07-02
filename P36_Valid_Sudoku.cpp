class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool result = 1;
        int row = board.size();
        int column = board[0].size();
        int check[9];
        for(int i = 0; i < row; ++i){
             memset(check, 0, sizeof(int)*9);
            for(int j = 0; j < column; ++j){
                if(board[i][j] != '.'){
                    int temp = board[i][j]-'0';
                     cout << temp;
                    check[temp - 1] += 1;
                    if(check[temp - 1] > 1) return 0;
                }
            }
        }
        for(int i = 0; i < column; ++i){
            memset(check, 0, sizeof(int)*9);
            for(int j = 0; j < row; ++j){
                if(board[j][i] != '.'){
                    int temp = board[j][i]-'0';
                    check[temp - 1] += 1;
                    if(check[temp - 1] > 1) return 0;
                }
            }
        }
        
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                memset(check, 0, sizeof(int)*9);
                for(int k = 0; k < 3; ++k){
                    for(int l = 0; l < 3; ++l){
                        if(board[i*3+k][j*3+l] != '.'){
                            int temp = board[i*3+k][j*3+l]-'0';
                            check[temp - 1] += 1;
                            if(check[temp - 1] > 1) return 0;
                        }
                    }
                }
            }
        }
        return result;
    }
};
