class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int n = nums.size();
        if(n < 1){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        int front = 0;
        int back = n;
        int position = (back + front) / 2;
        cout << position << endl;
        while(front < back){
            if(nums[position] < target){
                front = position + 1;
            }
            else if(nums[position] >  target){
                back = position - 1;
            }
            else{
                break;
            }
            position = (back + front) / 2;
        }
        cout << position;
        if(position >= n || position < 0){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        if(nums[position] != target){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        else{
            int starting = position;
            while(starting >= 0){
                if(nums[starting] != target) break; 
                starting--;
            }
            int ending = position;
            while(ending < n){
                if(nums[ending] != target) break;
                ending++;
            }
            result.push_back(starting + 1);
            result.push_back(ending - 1);
        }
        return result;
    }
};
