class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res;
        int n = nums.size();
        if(n == 0) return 0;
        res = nums[0];
        int current_sum = 0;
        for(int i = 0; i < n; i++){
            current_sum  = max(nums[i], nums[i] + current_sum);
            res = max(res, current_sum);
        }
        return res;
    }
};
