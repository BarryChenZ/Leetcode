class Solution {
public:
    int counter = 0;
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int i = 0;
        int temp = nums[0];
        while(i < n){
            if(nums[i] == temp){
                counter++;
            }
            else{
                temp = nums[i];
                counter = 1;
            }
            if(counter > 2){
                //remove
                nums.erase(nums.begin() + i);
                i = i - 1;
                n = n - 1;
                //counter = 0;
            }
            i++;
        }
        return n;
    }
};
