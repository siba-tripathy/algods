//https://leetcode.com/problems/validate-binary-search-tree
//AC
//Good question
//Give it a try



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
    
    int find_max(TreeNode* node) {
        while(node->right) {
            node = node->right;
        }
        return node->val;
    }
    
    int find_min(TreeNode* node) {
        while(node->left) {
            node = node->left;
        }
        return node->val;
    }
    
    bool isValidBST(TreeNode* root) {
        bool isLeftSatisfying = true;
        bool isRightSatisfying = true;
        
        if (root->left!= NULL) {
            isLeftSatisfying = root->val > root->left->val && isValidBST(root->left) && find_max(root->left) < root->val;
        }
        
        if (root->right!= NULL) {
            isRightSatisfying = root->val < root->right->val && isValidBST(root->right) && find_min(root->right) > root->val;
        }
        return isLeftSatisfying && isRightSatisfying;
    }
};