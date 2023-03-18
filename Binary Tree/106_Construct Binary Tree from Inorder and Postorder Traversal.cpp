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

    TreeNode* buildTree_helper(vector<int>& inorder, int i_start, int i_end, vector<int>& postorder, int p_start, int p_end){
        if(i_start > i_end || p_start > p_end)  return NULL;
        vector<int>::iterator iter;
        int root_val = postorder[p_end];
        iter = find(inorder.begin(), inorder.end(), root_val); //在inorder中寻找postorder的最后一个元素

        int i_start_left = i_start; 
        int i_end_left = iter - inorder.begin() - 1;
        int p_start_left = p_start;
        int p_end_left = p_start + i_end_left - i_start_left; //p左的结尾是p左的开头加上左子树的元素数量（i左end - i左start）

        int i_start_right = iter - inorder.begin() + 1; 
        int i_end_right = i_end;
        int p_start_right = p_start + i_end_left - i_start_left + 1; //p右start在原先基础上加上左子树元素后，再加1
        int p_end_right = p_end - 1; //p右end要-1因为最后一个元素去当了根节点

        TreeNode* node = new TreeNode(root_val);
        node->left = buildTree_helper(inorder, i_start_left, i_end_left, postorder, p_start_left, p_end_left);
        node->right = buildTree_helper(inorder, i_start_right, i_end_right, postorder, p_start_right, p_end_right);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int length = inorder.size();
        return buildTree_helper(inorder, 0, length - 1, postorder, 0, length - 1);
    }
};
