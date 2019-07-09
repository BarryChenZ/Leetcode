class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> res;
        res.push_back(nums);
        while(next_permutation(begin(nums), end(nums))) {
            if(nums != res.back())
                res.push_back(nums);
        }
        return res;
    }
};
