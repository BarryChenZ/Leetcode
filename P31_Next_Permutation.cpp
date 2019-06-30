class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        if(n > 1){
        for(int i = 0; i < n - 1; ++i){
            if(nums[i] >= nums[i+1]){
               temp.push_back(0); 
            }
            else{
               temp.push_back(1);     
            }
        }
        if(temp[n-2] == 0){
            int position = n-2;
            while(position > 0){
                if(temp[position] != 0) break;
                position --;
            }
            int higher = position;
            int dis = 1000;
            for(int i = position + 1; i < n; ++i){
                if(nums[i] > nums[position] && (nums[i] - nums[position]) < dis){
                    higher = i;
                    dis = nums[i] - nums[position];
                }
            }
            int a = nums[higher];
            nums[higher] = nums[position];
            nums[position] = a;
            int sorted_position = 1;
            if(higher == position) sorted_position = 0;
            for(int i = position + sorted_position; i < n; ++i){
                int low = i;
                cout << low << endl;
                for(int j = i + 1; j < n; ++j){
                    if(nums[low] > nums[j]){
                        low = j;
                    }
                }
                cout << low << endl;
                a = nums[low];
                nums[low] = nums[i];
                nums[i] = a;
            }
        }
        else{
            int a = nums[n-1];
            nums[n-1] = nums[n-2];
            nums[n-2] = a;
        }
        }
    }
};
