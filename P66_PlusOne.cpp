class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.back() < 9) {
            digits.back() = digits.back() + 1;
            return digits;
        }
        
        else {
            for(int i = digits.size() - 1; i >= 0; --i) {
                if (digits[i] + 1 == 10) {
                    digits[i] = 0;
                    if (i == 0) {
                        digits[0] = 1;
                        digits.push_back(0);
                        return digits;
                    }
                }
                
                else {
                    digits[i]++;
                    return digits;
                }
            }
        }
        return digits;
    }
};
