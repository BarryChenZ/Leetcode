class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        if(nums.size() < 1) return result;
        permutation(nums, temp, 0, nums.size());  
        return result;
    }
    void permutation(vector<int>& nums, vector<int>& temp, int k, int size){
        if(k == size){
            result.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            int temp_num = nums[i];
            temp.push_back(temp_num);
            nums.erase(nums.begin()+i);
            permutation(nums, temp, k+1, size);
            
            temp.pop_back();
            nums.insert(nums.begin()+i, temp_num);
        }
    }
};
