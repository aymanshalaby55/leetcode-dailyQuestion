/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        // bfs
        vector<int> ans;
        queue<TreeNode*> q;
        if(root)
        q.push(root);
        while (!q.empty()) {
            int ma = q.front()->val;
            cout << q.size() << endl;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* top = q.front();
                cout << top->val << \ \;
                ma = max(ma, top->val);
                q.pop();
                if (top->left) {
                    q.push(top->left);
                }
                if (top->right) {
                    q.push(top->right);
                }
            }
            cout << endl;
            ans.push_back(ma);
        }
        return ans;
    }
};