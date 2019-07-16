class Solution {
public:
        int counter = 0;
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res(50);
        int n = words.size();
        int i = 0;//輪到第i個word
        int k = 0;//計算要放入幾個進入vector
        int temp = 0;//
        int temp_size = 0;//i的size
        bool last = false;
        while(i < n){
            cout << i << endl;
            temp_size = words[i].size();
            if(temp + temp_size <= maxWidth){
                last = true;
                temp += temp_size;
                temp ++;
                k++;
            }
            else{
                add(words, res, i, k, maxWidth);
                k = 0;
                temp = 0;
                last = false;
                i--;
            }
            i++;
        }
        if(last == true) add_left(words, res, i, k, maxWidth);
        res.resize(counter);
        return res;
    }
    void add(vector<string>& words, vector<string>& res, int i, int k, int maxWidth){
        int space_n = 0;
        //計算幾格要插入空白
        if(k == 1) space_n = 1;
        else{
            space_n = k - 1;
        }
        int space_num[space_n];
        for(int j = 0; j < space_n; j++){
            space_num[j] = 0;
        }
        int temp = 0;
        //插入空白個數
        for(int j = 0; j < k; j++){
            temp += words[i - k + j].size();
        }
        //cout << temp << endl;
        temp = maxWidth - temp;
        int insert_space_pos = 0;
        while(temp > 0){
            space_num[insert_space_pos] += 1;
            insert_space_pos++;
            if(insert_space_pos == space_n) insert_space_pos = 0;
            temp --;
        } 
        //cout << space_num[0] << endl;
        //存入words
        for(int j = 0; j < k; j++){
            //cout << i - k + j;
            res[counter] += words[i - k + j];
            if(j < space_n){
                for(int x = 0; x < space_num[j]; x++){
                    res[counter].push_back(' ');
                }
            }
        }
        counter ++;
    }
    void add_left(vector<string>& words, vector<string>& res, int i, int k, int maxWidth){
        //計算幾格要插入空白
        int temp = 0;
        //插入空白個數
        for(int j = 0; j < k; j++){
            temp += words[i - k + j].size();
        }
        temp = maxWidth - temp;
        //存入words
        for(int j = 0; j < k; j++){
            res[counter] += words[i - k + j];
            if(j != k -1){
            res[counter].push_back(' ');
            temp --;
            }
        }
        for(int j = 0; j < temp; j++){
             res[counter].push_back(' ');
        }
        counter ++;
    }
};
