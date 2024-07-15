/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[][]} descriptions
 * @return {TreeNode}
 */
var createBinaryTree = function(des) {
    let mp = new Map();
    let child = new Set();

    des.forEach(([par, ch, isLeft]) => {
        if(!mp.has(par)){
            mp.set(par, new TreeNode(par));
        }
        if(!mp.has(ch)){
            mp.set(ch, new TreeNode(ch));
        }

        if(isLeft === 1){
            mp.get(par).left = mp.get(ch);
        } else {
            mp.get(par).right = mp.get(ch);
        }

        child.add(ch);
    });

    let root = null;
    for(let key of mp.keys()){
        if(!child.has(key)){
            root = mp.get(key);
            break;
        }
    }
    return root;
};