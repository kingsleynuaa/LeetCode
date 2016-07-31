/*
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
    void getPath(TreeNode * root, TreeNode* p, TreeNode* q, vector<TreeNode*> &Path, vector<TreeNode*> &Path1, vector<TreeNode*> &Path2)
    {
        if(root == NULL) return;
        Path.push_back(root);
        if(root == p) Path1 = Path;
        if(root == q) Path2 = Path;
        if (!Path1.empty() && !Path2.empty()) return;
        getPath(root->left, p, q, Path, Path1, Path2);
        getPath(root->right, p, q, Path, Path1, Path2);
        Path.pop_back();
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path,path1,path2;
        getPath(root, p, q, path, path1, path2);
        TreeNode* result = root;
        int index = 0;
        while (index < path1.size() && index < path2.size()) {
             if (path1[index] != path2[index]) break;
                else result = path1[index++];
         }
         
         return result;
        
        
    }
};
