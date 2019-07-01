class Solution {
public:
    int longestValidParentheses(string s) {
        int count = 0;
        int result = 0;
        int n = s.size();
        if(n <= 1) return result;
        int start = 0;
        int next_start = 0;
        while(s[start] !='('){
            start++;
            if(start > s.size()) return result;
        }
        while(start < s.size()){
            count = 0;
            for(int i = start; i < s.size(); i++){
                if(s[i] == '('){
                    count++;
                }
                else{
                    count--;
                }
                if(count == 0){
                    if(i - start + 1 > result) result = i - start + 1;
                }
                if(count < 0){
                    start = i+1;
                    while(s[start] !='(' && start < s.size()){
                        start++;
                    }
                    break;
                }
            }
            if(count >= 0) {
                start++;
                while(s[start] !='(' && start < s.size()){
                        start++;
                }
            }
        }
        cout << result;
        return result;
    }
};
