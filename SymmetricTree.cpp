/**
 *Defition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode* T1, TreeNode* T2)
    {
        if(T1 == NULL && T2 == NULL)
            return true;
        else if(T1 == NULL || T2 == NULL)
            return false;
        
        if(T1->val != T2->val)
            return false;
        else{
            return (isSymmetric(T1->left,T2->right) && isSymmetric(T1->right,T2->left));
        }
    }
};
