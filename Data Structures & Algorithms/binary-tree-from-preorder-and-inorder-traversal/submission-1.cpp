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
int preindex=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.empty()) return nullptr;

        int rootValue=preorder[preindex++];
        TreeNode* root=new TreeNode(rootValue);

        int index=0;
        while(inorder[index] != rootValue) {
            index++;
        }

        vector<int> left(inorder.begin(), inorder.begin()+index);
        vector<int> right(inorder.begin()+index+1, inorder.end());

        root->left=buildTree(preorder, left);
        root->right=buildTree(preorder,right);

        return root;

    }
};
