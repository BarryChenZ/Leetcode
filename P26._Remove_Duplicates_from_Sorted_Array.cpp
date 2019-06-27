class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator it;
        for(it = nums.begin(); it != nums.end(); ++it)
        {
            if(it != nums.begin() && *it == *(it-1))
            {
                it = nums.erase(it);
                it--;
            }
        }
        int len = nums.size();
        return len;
    }
};
