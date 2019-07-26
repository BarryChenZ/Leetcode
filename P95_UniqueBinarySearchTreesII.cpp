/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return generateTrees(1, n);
    }
    vector<TreeNode*> generateTrees(int m, int n){
        vector<TreeNode *> res;
        
        if (m > n) return {nullptr};
        if (m == n) return {new TreeNode(n)};
        if (m < n){
            for(int i = m; i <= n; i++){
                vector<TreeNode*> left = generateTrees(m, i - 1);
                vector<TreeNode*> right = generateTrees(i + 1, n);
                
                for (auto l : left) {
                    for (auto r : right) {
                        TreeNode* root = new TreeNode(i);
                        root->left = l;
                        root->right = r;
                        
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }
};
