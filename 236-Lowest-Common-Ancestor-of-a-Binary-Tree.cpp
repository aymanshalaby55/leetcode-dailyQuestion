/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* DFS(TreeNode* root, TreeNode* p, TreeNode* q, int v_p = 0,
                  int v_q = 0) {
        if (!root || root == p || root == q)
            return root;

        auto l = DFS(root->left, p, q, v_p, v_q);
        auto r = DFS(root->right, p, q, v_p, v_q);
        if(l && r){
            return root;
        }
        else if(!l){
            return r;
        }
        return l;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return DFS(root, p, q, 0, 0);
    }
};