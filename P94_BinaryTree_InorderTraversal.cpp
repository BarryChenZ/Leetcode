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
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return res;
        traval(root);
        return res;
    }
    void traval(TreeNode* root){
        if(root->left){
            traval(root->left);
        }
        res.push_back(root->val);
        if(root->right){
            traval(root->right);
        }
        return;
    }
};
