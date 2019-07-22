class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        bool res = false;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == target) return true;
            if(nums[i] > target) break;
        }
        return res;
    }
};
