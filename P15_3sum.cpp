class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3){
            return result;
        }
        sort(nums.begin(), nums.end());
        if (nums.front() > 0 || nums.back() < 0) return result;

        for(int i = 0; i < nums.size()-2; ++i){
            int sum = -1*nums[i];
            int front = i + 1, back = nums.size() - 1;
            while(front < back){
                if(sum > nums[front] + nums[back]) ++front;
                else if(sum < nums[front] + nums[back]) --back;
                else{
                    result.emplace_back(vector<int>{nums[i], nums[front], nums[back]});
                    ++front;
                    --back;
                    while (front < back && nums[front-1] == nums[front])
                        front++;
                    while (front < back && nums[back+1] == nums[back])
                        back--;
                }
            }
            while (i < nums.size() - 2 && nums[i] == nums[i + 1])
                i++;
        }
        return result;
    }
};
