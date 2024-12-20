
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
    vector<int> value;
    map<int, stack<int>> mp;
    void getAllOddValues(TreeNode* root) {
        if (root == nullptr)
            return;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {

            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            if (level & 1) {
                mp[level].push(node->val);
            }
            if (node->left != nullptr)
                q.push({node->left, level + 1});

            if (node->right != nullptr)
                q.push({node->right, level + 1});
        }
    }
    void assignNewValues(TreeNode* root) {
        if (root == nullptr)
            return;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {

            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            if (level & 1) {
                int value = mp[level].top();
                node->val = value;
                mp[level].pop();
            }
            if (node->left != nullptr)
                q.push({node->left, level + 1});

            if (node->right != nullptr)
                q.push({node->right, level + 1});
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        getAllOddValues(root);
        if (root == nullptr)
            return nullptr;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {

            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            if (level & 1) {
                int value = mp[level].top();
                node->val = value;
                mp[level].pop();
            }
            if (node->left != nullptr)
                q.push({node->left, level + 1});

            if (node->right != nullptr)
                q.push({node->right, level + 1});
        }
        return root;
    }
};