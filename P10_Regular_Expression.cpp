class Solution {
public:
    bool isMatch(string s, string p) {
        smatch temp;
        regex pattern(p);
        if(regex_search(s, temp, pattern)){
            //cout << temp.str() << endl;
            for(int i = 0; i < s.size(); ++i){
            if(s[i] != temp.str()[i]){
                //cout << s[i] << " " << temp.str()[i];
                return 0;
            }
        }
        }
        else{
            return 0;
        }
        return 1;
    }
};
