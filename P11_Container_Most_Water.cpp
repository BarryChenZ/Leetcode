class Solution {
public:
    int maxArea(vector<int>& height) {
        int Area = 0;
        int MAX_left = 0;
        int MAX_right = height.size()-1;
        int width = 0;
        int temp = 0;
        int height1 = (height[MAX_left] >= height[MAX_right])? height[MAX_right] : height[MAX_left];
        int shorter = (height[MAX_left] >= height[MAX_right])? 2 : 1;
        Area = (MAX_right-MAX_left)*height1;
        cout << MAX_left << MAX_right << endl;
        while(MAX_left < MAX_right){
           if(shorter == 1){
               while(height[MAX_left] <= height1 && MAX_left < MAX_right){
                   ++MAX_left;
                   cout << MAX_left << endl;
               }
           }
           else{
               while(height[MAX_right] <= height1 && MAX_left < MAX_right){
                   --MAX_right;
                   cout << MAX_right << endl;
               }
           }
            cout << MAX_left << MAX_right;
            shorter = (height[MAX_left] >= height[MAX_right])? 2 : 1;
            height1 = (shorter == 2)? height[MAX_right] : height[MAX_left];
            temp = (MAX_right-MAX_left)*height1;
            if(temp > Area) Area = temp;
        }
        return Area;
    }
};
