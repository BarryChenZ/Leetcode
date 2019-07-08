class Solution {
public:
    int counter = 0;
    int result = 100000;
    int jump(vector<int>& nums) {
        int n = nums.size();
        int *min_at_i = new int[n];
        for(int i = 0; i < n; i++){
            min_at_i[i] = 100000;
        }
        if(n <= 1) return 0;
        back_track(nums, 0, n-1, min_at_i);
        return result;
    }
    void back_track(vector<int>& nums, int index, int goal, int* min_at_i){
        for(int i = nums[index]; i >= 1; i--){
            if(index + i <= goal){
                counter += 1;
                if(counter <= min_at_i[index + i]){
                    min_at_i[index + i] = counter;
                    if(index + i == goal){
                        if(counter < result){
                            result = counter;
                        }   
                        counter -= 1;
                        break;
                    }
                    else{
                        back_track(nums, index + i, goal, min_at_i);
                        counter -= 1;
                    }
                }
                else{
                    counter -= 1;
                    break;
                }
            }
        }
    }
};
