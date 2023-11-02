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
    pair<int, int> count(TreeNode* root, int &ans){
        if(!root){
            return {-1, 0};
        }
        pair<int, int> left = count(root->left, ans);
        pair<int, int> right = count(root->right, ans);
        
        int l = 0, r = 0;
        if(left.first != -1) l = left.first;
        if(right.first != -1) r = right.first;
        
        int n = left.second + right.second;
        int avg = (root->val + l + r)/(1+n);
        
        if(avg == root->val) ans++;
        
        return {(root->val + l + r), n+1};
    }
    
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        count(root, ans);
        return ans;
    }
};