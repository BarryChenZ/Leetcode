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
    bool isValidBST(TreeNode* root) {
        bool res = true;
        if(!root) return res;
        int temp = root->val;
        res = valid(root);
        return res;
    }
    bool right(TreeNode* root, int temp){
        bool tmp = true;
        if(root->val <= temp) return false;
        if(root->right){
            tmp = right(root->right, temp);
        }
        if(root->left && tmp == true){
            tmp = right(root->left, temp);
        }
        return tmp;
    }
    bool left (TreeNode* root, int temp){
        bool tmp = true;
        if(root->val >= temp) return false;
        if(root->right){
            tmp = left(root->right, temp);
        }
        if(root->left && tmp == true){
            tmp = left(root->left, temp);
        }
        return tmp;
    }
    bool valid (TreeNode* root){
        bool result = true;
        int temp = root->val;
        if(root->right){
            result = right(root->right, temp);
            if(result == true) result = valid(root->right);
        }
        if(root->left && result == true){
            result = left(root->left, temp);
            if(result == true) result = valid(root->left);
            cout << result;
        }
        return result;
    }
};


//參考
class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        if (!root) return true;
        vector<int> vec;
        traverse(vec, root);
        for (int i=0; i<vec.size()-1; i++)
        {
            if (vec[i]>=vec[i+1])
                return false;
        }
        return true;
    }

    void traverse(vector<int>& vec, TreeNode* root)
    {
        if (!root) return ;
        traverse(vec, root->left);
        vec.push_back(root->val);
        traverse(vec, root->right);
    }
};
