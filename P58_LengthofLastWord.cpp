class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int n = s.size();
        if(n < 1) return res;
        int i = n -1;
        while(i >= 0){
            if(s[i] == ' '){
                i--;
            }
            else{
                break;
            }
        }
        while(i >= 0){
            if(s[i] != ' '){
                res++;
            }
            else{
                break;
            }
            i--;
        }
        return res;
    }
};
