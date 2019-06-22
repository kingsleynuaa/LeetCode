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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        vector<int> temp;
        
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode* tempNode;
        int flag = 0;
        int count = 1;
        while(!q.empty())
        {
            temp.clear();
            flag = 0;
            for(int i = 0; i < count; i++)  //count表示这一层需要pop几次，就是有几个元素
            {
                tempNode = q.front();
                q.pop();
                temp.push_back(tempNode->val);
                cout << tempNode->val << " ";
            
                if(tempNode->left != NULL)
                {
                    q.push(tempNode->left);
                    flag++;
                }
                
                if(tempNode->right != NULL)
                {
                    q.push(tempNode->right);
                    flag++;
                }
              }
           
             count = flag;
             result.push_back(temp);
        }
        
        reverse(result.begin(), result.end());
        return result;
}

};
