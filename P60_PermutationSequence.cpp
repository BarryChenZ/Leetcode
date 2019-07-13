class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        int nums[n];
        for(int i = 0; i < n; i++){
            nums[i]=  i+1;
        }
        if(k == 1){
           for(int i = 0; i < n; i++){
                res.push_back(nums[i] + '0');
            } 
            return res;
        }
        int j = 1;
        sort(nums, nums + n);
        while(next_permutation(nums, nums + n)){
            j++;
            if(j == k){
                for(int i = 0; i < n; i++){
                    cout << nums[i];
                    res.push_back(nums[i] + '0');
                }
                break;
            }
        }
        return res;
    }
};
