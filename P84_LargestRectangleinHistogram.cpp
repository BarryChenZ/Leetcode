class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();
        if(n < 1) return 0;
        int left_max[n];
        int right_max[n];
        int counter = 0;
        int cur = -1;
        for(int i = 0; i < n; i++){
            counter = 0;
            if(cur == heights[i]) {
                right_max[i] = 0;
                continue;
            }
            cur = heights[i];
            for(int j = i + 1; j < n; j++){
                if(min(heights[i],heights[j]) == heights[i]) counter++;
                else break;
            }
            right_max[i] = counter;
        }
        cur = -1;
        for(int i = n - 1; i >= 0; i--){
            counter = 0;
            if(cur == heights[i]) {
                left_max[i] = 0;
                continue;
            }
            for(int j = i - 1; j >= 0; j--){
                if(min(heights[i],heights[j]) == heights[i]) counter++;
                else break;
            }
            left_max[i] = counter;
        }
        for(int i = 0; i < n; i++){
            int length = left_max[i] + right_max[i] + 1;
            int temp = length * heights[i];
            if(temp > res) res = temp;
        }
        return res;
    }
};
