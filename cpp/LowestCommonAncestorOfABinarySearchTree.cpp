/**
 * Defition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
#define max(a, b)  (((a) > (b)) ? (a) : (b))
#define min(a, b)  (((a) < (b)) ? (a) : (b))
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == NULL || q == NULL)  
            return NULL;
        if(max(p->val,q->val) < root->val)
            return lowestCommonAncestor(root->left,p,q);
        else if(min(p->val,q->val) > root->val)
            return lowestCommonAncestor(root->right,p,q);
        else return root;
    }
};
