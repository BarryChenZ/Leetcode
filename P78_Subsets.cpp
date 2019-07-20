class Solution {
public:
    vector<int> temp_comb;
    int counter = 0;
    vector<vector<int>> subsets(vector<int>& nums) {
        long size = 0;
        for(int j = 0; j <= nums.size(); j++){
            int temp = 1;
            for(int i = 0; i < j; i++){
                temp *= nums.size() - i;
            }
            for(int i = j; i > 0; i--){
                temp /= i;
            }
            size += temp;
        }
        vector<vector<int>> res(size);
        
        for(int i = 0; i <= nums.size(); i++){
            comb(res, nums, 0, i);
        }
        return res;
        
    }
    void comb(vector<vector<int>>& res, vector<int>& nums, int pos, int k){
        if(k == 0){
            res[counter] = temp_comb;
            counter++;
            return;
        }
        for(int i = pos; i < nums.size(); i++){
            temp_comb.push_back(nums[i]);
            comb(res, nums, i + 1, k - 1);
            temp_comb.pop_back();
        }
        return;
    }
};
