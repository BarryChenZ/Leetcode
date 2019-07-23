//參考
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;
        
        string aComp1 = s1;
        string aComp2 = s2;
        
        int aLen = s1.size();
        
        sort(aComp1.begin(), aComp1.end());
        sort(aComp2.begin(), aComp2.end());
        if (aComp1 != aComp2) { return false; }
        
        for (int i=1;i<s1.size();i++) {
            
            string aComps11 = s1.substr(0, i);
            string aComps12 = s1.substr(i);
            
            string aComp1s21 = s2.substr(0, i);
            string aComp1s22 = s2.substr(i);
            
            string aComp2s21 = s2.substr(aLen - i);
            string aComp2s22 = s2.substr(0, aLen - i);
            
            if (isScramble(aComps11, aComp1s21) && isScramble(aComps12, aComp1s22)) {
                return true;
            }
            
            if (isScramble(aComps11, aComp2s21) && isScramble(aComps12, aComp2s22)) {
                return true;
            }
        }
        
        return false;
    }
};
