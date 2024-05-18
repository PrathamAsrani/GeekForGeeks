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
    int moves = 0;

    int inOrder(TreeNode *root){
        if(!root) return 0;
        int left = inOrder(root->left);
        int right = inOrder(root->right);
        moves += abs(left) + abs(right);
        return root->val + left + right - 1; // total coins - 1
    }
public:
    int distributeCoins(TreeNode* root) {
        inOrder(root);
        return moves;
    }
};