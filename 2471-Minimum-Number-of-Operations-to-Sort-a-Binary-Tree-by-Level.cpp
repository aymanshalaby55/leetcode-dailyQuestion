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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            int si = q.size();
            vector<int> values;
            for (int i = 0; i < si; i++) {
                TreeNode* top = q.front();
                q.pop();
                values.push_back(top->val);
                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
            }
            vector<int> sorted = values;
            float cntr = 0;
            sort(sorted.begin(), sorted.end());
            map<int , int> mp;
            for(auto i : values){
                mp[i] = cntr++;
            }
            cntr =0;
            for (int i = 0; i < values.size(); i++){
                cntr += values[i] != sorted[i];
                mp[values[i]] = mp[sorted[i]];
                swap(values[mp[sorted[i]]] , values[i]);
            }
            ans += cntr;
        }
        return ans;
    }
};