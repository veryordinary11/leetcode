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
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL)    return true;
        queue<TreeNode*> record;
        record.push(root);
        while(record.front() != nullptr){
            TreeNode* node = record.front();
            record.pop();
            record.push(node->left);
            record.push(node->right);
        }

        while(record.front() == nullptr){
            record.pop();
        }

        return record.empty();
    }
};

//BFS遍历树，遇到空节点也压入，最后把队头所有的空节点移出，如果队列非空则二叉树不完全
