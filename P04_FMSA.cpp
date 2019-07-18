class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median;
        int total_size;
        int median_position;
        total_size = nums1.size() + nums2.size();
        if(total_size%2 == 1){
            median_position = total_size/2 + 1;
            int count_1 = 0;
            int count_2 = 0;
            int total_count = 0;
            int which_num = 0;
            int empty_array = 0;
            for(int i = 0; i < median_position; ++i){
                if(nums1.size() == 0) empty_array = 1;
                if(nums2.size() == 0) empty_array = 2;
                if(empty_array == 1){
                    which_num = 2;
                    ++count_2;
                }
                else if(empty_array == 2){
                    which_num = 1;
                    ++count_1;
                }
                else if(nums1[count_1] < nums2[count_2] && empty_array == 0){
                        which_num = 1;
                        ++count_1;
                        if(count_1 == nums1.size()) empty_array = 1;
                }
                else if(nums1[count_1] > nums2[count_2] && empty_array == 0){   
                        which_num = 2;
                        ++count_2;
                        if(count_2 == nums2.size()) empty_array = 2;
                }
                else{ //nums1 == nums2
                    if(nums1.size() >= nums2.size()){
                        which_num = 1;
                        ++count_1;
                    }
                    else{
                        which_num = 2;
                        ++count_2;
                    }
                }
            }
            if(which_num == 1) median = nums1[count_1 - 1];
            else               median = nums2[count_2 - 1];
        }
        else{
            int median_left = 0;
            int median_right = 0;
            median_position = total_size/2;
            median_left = median_position - 1;
            median_right = median_position;
            int count_1 = 0;
            int count_2 = 0;
            vector<double> combine_vector(total_size);
            for(int i = 0; i < total_size; ++i){
                if(nums1.size() == 0 || count_1 == nums1.size()){
                    combine_vector[i] = nums2[count_2];
                    ++count_2;
                }
                else if(nums2.size() == 0 || count_2 == nums2.size()){
                    combine_vector[i] = nums1[count_1];
                    ++count_1;
                }
                else if(nums1[count_1] < nums2[count_2]){
                    combine_vector[i] = nums1[count_1];
                    ++count_1;
                }
                else if(nums1[count_1] > nums2[count_2]){   
                    combine_vector[i] = nums2[count_2];
                    ++count_2;
                }
                else{ //nums1 == nums2
                    if(nums1.size() >= nums2.size()){
                        combine_vector[i] = nums1[count_1];
                        ++count_1;
                    }
                    else{
                        combine_vector[i] = nums2[count_2];
                        ++count_2;
                    }
                }
                }
                median = (combine_vector[median_left] +                                                       combine_vector[median_right])/2;
            }
        return median;
        }
};
