class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result = vector<string>();
        backtrack(result, "", 0, 0, n);
        return result;
    }
    void backtrack(vector<string>& ans, string cur, int left, int right, int max) {
        if (cur.size() == max*2) {
            ans.push_back(cur);
            return;
        }
        if (left < max) {
            backtrack(ans, cur + "(", left+1, right, max);
        }
        if (right < left) {
            backtrack(ans, cur + ")", left, right+1, max);
        }
    }
};
