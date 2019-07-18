class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int temp[100];
        int i = 0;
        while(true){
            temp[i] = x%10;
            x = x/10;
            ++i;
            if(x == 0) break;
        }
        
        for(int j = 0; j < i; ++j){
            result += temp[j]*pow(10,i-1-j);
            if(result >= pow(2,31)-1 || result <= -1*pow(2,31)) {
                result = 0;
                break;
            }
        }
        return result;
    }
};
