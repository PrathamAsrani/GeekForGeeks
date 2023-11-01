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
    void inOrder(TreeNode* root, map<int, int> &mpp){
        if(root){
            inOrder(root->left, mpp);
            mpp[root->val]++;
            inOrder(root->right, mpp);
        }
    }
    vector<int> findMode(TreeNode* root) {
        map<int, int> mpp;
        vector<int> ans;
        inOrder(root, mpp);
        int mx = 0;
        for(auto i:mpp) if(i.second > mx) mx = i.second;
        for(auto i:mpp) if(i.second == mx) ans.push_back(i.first);
        return ans;
    }
};