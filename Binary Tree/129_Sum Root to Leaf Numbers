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
    int sum = 0;

    void helper(TreeNode* root, int cursum){
        if(root->left == nullptr && root->right == nullptr){
            sum += cursum;
            return;
        }
        if(root->left != nullptr){
            helper(root->left,cursum*10 + root->left->val);
        }
        if(root->right != nullptr){
            helper(root->right,cursum*10 + root->right->val);
        }
    }
    int sumNumbers(TreeNode* root) {
        if(root == nullptr) return 0;
        helper(root,root->val);
        return sum;
    }
};

//方法类似112题，先构造一个辅助函数，然后遍历二叉树，将最后的结果存储在一个全局变量中
