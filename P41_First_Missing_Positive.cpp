class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int result = 1;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 0) return 1;
        int i = 0;
        while(i < n){ 
            if(nums[i] <= 0) i++;
            else{
                break;
            }
        }
        cout << n;
        cout << i;
        int j = i;
        if(j == n) j = i-1;
        else j = i;
        cout << j;
        if(nums[j] <= 0) return 1;
        else if(nums[j] > 1) return 1;
        else{
            int smallest = 1;
            for(int k = j; k < nums.size(); ++k){
                cout << k;
                if(nums[k] <= smallest) smallest = nums[k] + 1;
                else{
                    break;
                }
            }
            result = smallest;
        }
        return result;
    }
};
