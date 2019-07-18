class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        char temp[numRows][1000] = {'\0'};
        int col = 0;
        int row = 0;
        int return_start = 0;
        for(int i = 0; i < s.size(); ++i){
            if(row < numRows && return_start == 0){
                temp[row][col] = s[i];
                row++;
                if(row >= numRows) {
                    return_start = 1;
                    if(numRows == 1) row = numRows - 1;
                    else{
                        row = numRows - 2;
                    }
                    col += 1;
                }
            }
            else{
                temp[row][col] = s[i];
                    row -= 1;
                    col += 1;
                if(row <= 0 && numRows == 2){
                    row = 1;
                    col -= 1;
                    return_start = 0;
                }
                if(row <= 0 && numRows != 2){
                    row = 0;
                    return_start = 0;
                }
            }
        }
        for(int i = 0; i < numRows; ++i){
            for(int j = 0; j < 1000; ++j){
                if(temp[i][j] != '\0') result += temp[i][j];
            }
        }
           
        return result;
    }
};
