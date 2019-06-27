class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator it;
        for(it = nums.begin(); it != nums.end(); ++it)
        {
            if(*it == val)
            {
                it = nums.erase(it);
                it--;
            }
        }
        int len = nums.size();
        return len; 
    }
};
