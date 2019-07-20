class Solution {
public:
    vector<int> temp_comb;
    int counter = 0;
    vector<vector<int>> combine(int n, int k) {
        long size = 1;
        for(int i = 0; i < k; i++){
            size *= n - i;
        }
        for(int i = k; i > 0; i--){
            size /= i;
        }
        cout << size;
        vector<vector<int>> res(size);
        vector<int> temp;
        for(int i = 0; i < n; i++){
            temp.push_back(i + 1);
        }
        comb(res, temp, 0, k);
        return res;
    }
    void comb(vector<vector<int>>& res, vector<int>& temp, int pos, int k){
        if(k == 0){
            res[counter] = temp_comb;
            counter++;
            return;
        }
        for(int i = pos; i < temp.size(); i++){
            temp_comb.push_back(temp[i]);
            comb(res, temp, i + 1, k - 1);
            temp_comb.pop_back();
        }
        return;
    }
};
