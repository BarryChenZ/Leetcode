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
    bool change = false;
    void recoverTree(TreeNode* root) {
        if(!root) return;
        valid(root);
        return;
    }
    void right(TreeNode* root, TreeNode* temp){
        if(root->val <= temp->val){
            int top = root->val;
            root->val = temp->val;
            temp->val = top;
            change = true;
        }
        if(root->right){
            right(root->right, temp);
        }
        if(root->left){
            right(root->left, temp);
        }
        return;
    }
    void left (TreeNode* root, TreeNode* temp){ //當前,原本
        if(root->val >= temp->val){
            int top = root->val;
            root->val = temp->val;
            temp->val = top;
            change = true;
        }
        if(root->right){
            left(root->right, temp);
        }
        if(root->left){
            left(root->left, temp);
        }
        return;
    }
    void valid (TreeNode* root){
        TreeNode *temp = root;
        change = false;
        if(root->right){
            right(root->right, temp);
            if(change == true) valid(root);
            else valid(root->right);
        }
        if(root->left){
            left(root->left, temp);
            if(change == true) valid(root);
            else valid(root->left);
        }
        return;
    }
};
