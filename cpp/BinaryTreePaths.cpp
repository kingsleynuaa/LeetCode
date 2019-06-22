/**
 Defition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//仍然是递归的思想
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        
        if(root == NULL) return result;
        
        binaryTreePaths(root, to_string(root->val), result);
        
        return result;
        
    }
    
    void binaryTreePaths(TreeNode* root, string t, vector<string> &result)
    {
        if(!root->left && !root->right)
        {
            result.push_back(t);
            return;
        }
        
        if(root->left) binaryTreePaths(root->left, t + "->" + to_string(root->left->val),result);
        if(root->right) binaryTreePaths(root->right, t + "->" + to_string(root->right->val),result);
        
    }
};
