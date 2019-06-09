class Solution {
public:
    unordered_map<char,string> numToString {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
    
    void tryCombinations( string& mainString, int index, string combination, vector<string>& result){
        int length = mainString.length();
        if(index >= length){ result.push_back(combination); return;}
        
        string tryChars = numToString.at(mainString[index]);
        for(auto a : tryChars){
            tryCombinations(mainString, index+1, combination+a, result);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.length() > 0){
            tryCombinations(digits, 0, "",result);
        }
        return result;
    }
};
