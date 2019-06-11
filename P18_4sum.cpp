class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() < 4){
            return result;
        }
        sort(nums.begin(), nums.end());
        if (nums.front() > 0 || nums.back() < 0) return result;
        int j = nums.size()-1;
        for(int i = 0; i < nums.size()-3; ++i){
            for(int j = nums.size()-1; j > 2; j--){
            int sum = target -1*(nums[i]+nums[j]);
            int front = i + 1, back = j - 1;
                while(front < back){
                    if(sum > nums[front] + nums[back]) ++front;
                    else if(sum < nums[front] + nums[back]) --back;
                    else{
                        result.emplace_back(vector<int>{nums[i], nums[front], nums[back], nums[j]});
                        ++front;
                        --back;
                        while (front < back && nums[front-1] == nums[front])
                            front++;
                        while (front < back && nums[back+1] == nums[back])
                            back--;
                }
            }
            while (j > 2 && j - i > 2 && nums[j] == nums[j - 1])
                j--;
            }
             while (i < nums.size() - 3 && j - i > 2 && nums[i] == nums[i + 1])
                i++;
            
        }
        return result;
    }
};
