class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return;
        for(int i = 0; i < n; i++){
            int temp = i;
            for(int j = i + 1; j< n; j++){
                if(nums[temp] > nums[j]){
                    temp = j;
                }
            }
            int tmp = nums[temp];
            nums[temp] = nums[i];
            nums[i] = tmp;
        }
        return;
    }
};
