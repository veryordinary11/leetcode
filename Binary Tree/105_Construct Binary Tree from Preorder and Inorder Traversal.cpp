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
    TreeNode* buildTree_helper(vector<int>& preorder, int p_start, int p_end, vector<int>& inorder, int i_start, int i_end){
        if(p_start>p_end || i_start>i_end)  return NULL;
        vector<int>::iterator iter;
        int root_val = preorder[p_start];//根节点的值为preorder的第一个元素值
        iter = find(inorder.begin(),inorder.end(),root_val);
        int root_index = iter - inorder.begin();//在inorder中找到根节点的值对应的index
        int left_num = root_index - i_start;//左子树拥有的元素个数
        TreeNode* node = new TreeNode(root_val);
        node->left = buildTree_helper(preorder, p_start+1, p_start+left_num, inorder, i_start, i_start+left_num-1);
        node->right = buildTree_helper(preorder, p_start+left_num+1, p_end, inorder, root_index+1, i_end);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int length = preorder.size();
        return buildTree_helper(preorder,0,length-1,inorder,0,length-1);
    }
};
