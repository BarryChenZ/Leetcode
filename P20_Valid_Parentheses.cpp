class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n%2==1) return 0;
        int point = 0;
        vector<char> temp;
        for(int i = 0; i <n; ++i){
            if(s[i] == '(' ||s[i] == '[' ||s[i] == '{') temp.push_back(s[i]);
            else{
                if(temp.empty()) return 0;
                char a = temp.back();
                switch(a){
                    case '(':
                        if(s[i] != ')') return 0;
                        temp.pop_back();
                        break;
                    case '[':
                        if(s[i] != ']') return 0;
                        temp.pop_back();
                        break;
                    case '{':
                        if(s[i] != '}') return 0;
                        temp.pop_back();
                        break;
                }
            }
        }
        if(temp.empty()) return 1;
        else return 0;
    }
};
