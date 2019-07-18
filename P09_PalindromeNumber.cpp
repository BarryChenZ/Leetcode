class Solution {
public:
    bool isPalindrome(int x) {
        if(x*-1 > 0) return 0;
        char temp[100];    
        sprintf(temp, "%d", x);
        size_t length = strlen(temp);
        for(int i = 0; i < length; ++i){
            if(temp[i] != temp[length-i-1]) return 0;
        }
        return 1;
    }
};
