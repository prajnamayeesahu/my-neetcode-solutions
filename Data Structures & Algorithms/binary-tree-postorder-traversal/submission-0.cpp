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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int> res;
        TreeNode* curr=root;

        while (curr || !stack.empty()) {
            if (curr) {
                res.push_back(curr->val);
                stack.push(curr);
                curr = curr->right;
            } else {
                curr = stack.top();
                stack.pop();
                curr = curr->left;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};