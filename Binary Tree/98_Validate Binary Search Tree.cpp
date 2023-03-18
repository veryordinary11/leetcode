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
    vector<int> arr;

    void Inorder(TreeNode* root,vector<int>& arr){
        if(root == NULL)    return;
        Inorder(root->left,arr);
        arr.push_back(root->val);
        Inorder(root->right,arr);
    }

    bool isValidBST(TreeNode* root) {
        Inorder(root,arr);
        bool flag = true;
        for(int i = 1;i < arr.size(); i++){
            if(arr[i] <= arr[i-1]) flag = false;
        }
        return flag;
    }
};

//二叉搜索树的中序遍历序列是严格递增的，充要条件
