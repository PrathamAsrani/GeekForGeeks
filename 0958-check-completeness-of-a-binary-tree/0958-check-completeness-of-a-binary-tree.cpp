/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool null = false;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                if(null)
                    return 0;
                else 
                    q.push(curr->left);
            }else
                null = true;
            if(curr->right){
                if(null)
                    return 0;
                else 
                    q.push(curr->right);
            }else
                null = true;
        }
        return 1;
    }
};