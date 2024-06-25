/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func bstToGst(root *TreeNode) *TreeNode {
    sum := 0
    var fun func(*TreeNode)
    fun = func(root *TreeNode) {
        if root == nil {
            return 
        }
        fun(root.Right);
        sum += root.Val;
        root.Val = sum;
        fun(root.Left);
    };
    fun(root);
    return root;
}