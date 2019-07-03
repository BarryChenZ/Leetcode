class Solution {
public:
    bool row[9][9], col[9][9], square[9][9]; //前:第幾行or第幾列 後:那一行or那一列的九位數
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int temp = board[i][j]-'1';
                    row[i][temp] = true;
                    col[j][temp] = true;
                    square[i/3*3+j/3][temp] = true;
                }
            }
        }
        search(board, 0, 0);
    }
    bool search(vector<vector<char>>& board, int r, int c){
        if(r == 9)
             return true;
        if(board[r][c] != '.'){
            int cc = c!=8 ? c+1:0;
            int rr = c!=8 ? r : r+1;
            return search(board, rr, cc);
        }
        for(int i = 0; i < 9; i++){
            if(!row[r][i] && !col[c][i] && !square[r/3*3+c/3][i]){
                board[r][c] = i +'1';
                row[r][i] = true;
                col[c][i] = true;
                square[r/3*3 + c/3][i] = true;
                int cc = c!=8 ? c+1:0;
                int rr = c!=8 ? r : r+1;
                if(search(board, rr, cc)){
                    return true;
                }
                else{
                    board[r][c] = '.';
                    row[r][i] = false;
                    col[c][i] = false;
                    square[r/3*3 + c/3][i] = false;
                }
            }
        }
        return false;
    }
};
