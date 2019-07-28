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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> temp1;
        vector<int> temp2;
        vector<int> temp11;
        vector<int> temp22;
        input(p, temp1, temp11, 0);
        input(q, temp2, temp22, 0);
        if(temp1.size() != temp2.size()) return false;
        for(int i = 0; i < temp1.size(); i++){
            if(temp1[i] != temp2[i] || temp11[i] != temp22[i]) return false;
        }
        return true;
    }
    void input(TreeNode* root, vector<int>& temp, vector<int>& temp_struc, int i){
        if(!root) return;
        input(root->right, temp, temp_struc, 1);
        temp.push_back(root->val);
        temp_struc.push_back(i);
        input(root->left, temp, temp_struc, 2);
    }
};
