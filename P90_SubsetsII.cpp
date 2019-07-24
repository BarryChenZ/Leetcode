class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        res.push_back(temp);
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++){
            input(temp, nums, i + 1, 0);
        }
        return res;
    }
    void input(vector<int>& temp, vector<int>& nums, int i, int pos){
        if(temp.size() == i){
            res.push_back(temp);
            return;
        }
        for(int j = pos; j < nums.size();){
            int num = nums[j];
            temp.push_back(num);
            input(temp, nums, i, j + 1);
            temp.pop_back();
            j++;
            while(j < nums.size() && nums[j] == nums[j - 1]){
                j++;
            }
        }
    }
};
