class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0)  {
            nums1 = nums2;
            return;
        }
        if(n == 0) return;
        int i = 0;
        while(nums2.size() > 0){
            if(nums2[0] <= nums1[i] || i >= m + n - nums2.size()){
                cout << nums2[0] << endl;
                nums1.insert(nums1.begin() + i, nums2[0]);
                nums2.erase(nums2.begin() + 0);
            }
            i++;
        }
        nums1.resize(m+n);
        return;
    }
};
