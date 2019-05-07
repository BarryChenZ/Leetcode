class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int start = 0;
        int end = 0;
        int count = 0;
        int k = 0;
        int i,j;
        
           for( i = 0; i < s.size(); ++i){
            start = i;
            count = 1;
            for(j = i+1; j< s.size(); ++j){
                end = 0;
                for(int k = start; k < j; ++k){
                    if(s[k] == s[j]){
                    if(count >= result){
                        result = count;
                    }
                    end = 1;
                    break;
                    }
                }
                if(end == 1) break;
                ++count;
            }
            if(count >= result){
                result = count;
            }
        }
        return result;
    }
};
