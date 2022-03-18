//https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/submissions/
//AC


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
    
    void convertToGreaterSum(TreeNode* root, int& sum) {
        if(!root) {
            return;
        }
        convertToGreaterSum(root->right, sum);
        sum+=root->val;
        root->val = sum;
        convertToGreaterSum(root->left, sum);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        convertToGreaterSum(root, sum);
        return root;
    }
};