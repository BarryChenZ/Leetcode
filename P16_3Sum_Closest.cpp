class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0;
        int distance = 0;
        int closet = 1000;
        if(nums.size() < 3){
            return result;
        }
        sort(nums.begin(), nums.end());
        //if (nums.front() > 0 || nums.back() < 0) return result;
        for(int i = 0; i < nums.size()-2; ++i){
            int sum = nums[i];
            int front = i + 1, back = nums.size() - 1;
            while(front < back){
                distance = abs(sum + nums[front] + nums[back] - target);
                cout << distance << endl;
                if(distance < closet) {
                    closet = distance;
                    result = sum + nums[front] + nums[back];
                }
                if(sum + nums[front] + nums[back] < target) ++front;
                else if(sum + nums[front] + nums[back] > target) --back;
                else{
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
