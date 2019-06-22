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
    bool DFS(TreeNode* node, int sum, int curSum)
    {
        if(node == NULL) return false;
        
        if(node->left == NULL && node->right == NULL)
            return sum == curSum + node->val;
        return DFS(node->left,sum,curSum+node->val) || DFS(node->right,sum,curSum+node->val);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return DFS(root,sum,0);
        
        
    }
};
