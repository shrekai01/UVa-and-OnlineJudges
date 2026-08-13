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
    // tree, DFS
    void preorder(vector<int> &arr, TreeNode *root){
        if(!root) return;
        arr.push_back(root->val);
        preorder(arr, root->left);
        preorder(arr, root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(res, root);
        return res;
    }
    // O(n) time, O(h) extra-space, where n is the number of nodes in the binary tree and h is the height of it
};