/**
 *Defition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//今天突然有一种感觉，是对于递归的理解，尤其是在二叉树相关的题目中，递归的理解，那就是：
//将树抽象成三个部分：根节点，左子树，右子树。每次考虑问题的时候，假设左右子树都已经算出了结果，如此抽象，感觉比较简单。
//目前仍然存在一个问题就是：将递归的解法很好的转换成非递归的解法，还没有一个得心应手的感觉
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int left = getDepth(root->left,0);
        cout << "left:" << left << endl;
        int right = getDepth(root->right,0);
        cout << "right:" << right << endl;
        if((left - right) > 1 || (right - left) > 1)
            return false;
        else return isBalanced(root->left) && isBalanced(root->right);
        
    }
    
    int getDepth(TreeNode* root, int depth)
    {
        if(root == NULL) return depth;
        int left = getDepth(root->left,depth+1);
        int right  = getDepth(root->right,depth+1);
        return left >= right ? left : right;
    }
};
