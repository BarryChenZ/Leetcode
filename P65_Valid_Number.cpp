class Solution {
public:
    bool isNumber(string s) {
        trim(s);
        if (!s.empty() && (s[0] == '-' || s[0] == '+')){
            s = s.substr(1);
        }
        if (s.empty()){
            return false;
        }
        if (isInteger(s) || isFloat(s) || isScientific(s)){
            return true;
        }
        return false;
        
    }
    void trim(string& s){
        int pos1 = s.find_first_not_of(' ');
        int pos2 = s.find_last_not_of(' ');
        if (pos1 == string::npos || pos2 == string::npos){//在字尾結束符
            return;
        }
        s = s.substr(pos1, pos2 - pos1 + 1);
    }
    bool isInteger(string& s){//純數字
        if(!s.empty() && s.find_first_not_of("0123456789") == string::npos){
            return true;
        }
        return false;
    }
    bool isFloat(string& s){
        if(s.empty() || s.find('.') == string::npos){
            return false;
        }
        int pos = s.find('.');
        string before = s.substr(0, pos);
        string after = s.substr(pos + 1);
        // .
        if (before.empty() && after.empty()){
            return false;
        }
        // || for .3 or 3.
        if((before.empty() || isInteger(before)) && (after.empty() || isInteger(after))){
            return true;
        }
        return false;
    }
    bool isScientific(string& s){
        if(s.empty() || s.find('e') == string::npos){
            return false;
        }   
        
        int pos = s.find('e');
        string before = s.substr(0, pos);
        string after = s.substr(pos+1);
        
        if (!after.empty() && (after[0] == '-' || after[0] == '+')) {
            after = after.substr(1);
        }      
        if ((isInteger(before) || isFloat(before)) && (isInteger(after))) {
            return true;
        }
        return false;
    }
};
