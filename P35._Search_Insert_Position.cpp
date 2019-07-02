class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 1) return 0;
        int position = 0;
        while(position < n){
            if(nums[position] == target) break;
            else if(nums[position] < target) ++position;
            else{
                break;
            }
        }
        return position;
    }
};
