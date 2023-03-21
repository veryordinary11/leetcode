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
    vector<int> arr_inorder;
    vector<int> arr_preorder;

    void Preorder(TreeNode* root, vector<int>& arr){
        if(root == NULL)    return;
        arr.push_back(root->val);
        Preorder(root->left,arr);
        Preorder(root->right,arr);
    }//先序遍历

    void Inorder(TreeNode* root, vector<int>& arr){
        if(root == NULL)    return;
        Inorder(root->left, arr);
        arr.push_back(root->val);
        Inorder(root->right, arr);
    }//中序遍历

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
    }//用中序遍历和先序遍历构建一棵树

    void fix_preorder(vector<int>& preorder, vector<int>& inorder){
        int err1 = 0;
        int err2 = 0;
        vector<int> temp = inorder;
        sort(temp.begin(),temp.end());
        for(int i = 0; i < inorder.size(); i++){
            if(temp[i] != inorder[i]){
                err1 = temp[i];
                err2 = inorder[i];
                break;
            }
        }
        swap_preorder(preorder, err1, err2);
    }//把原本错位节点树的先序遍历改成正确BST树的先序遍历序列

    void swap_preorder(vector<int>&preorder, int err1, int err2){
        vector<int>::iterator it1 = std::find(preorder.begin(),preorder.end(),err1);
        int idx1 = std::distance(preorder.begin(),it1);
        vector<int>::iterator it2 = std::find(preorder.begin(),preorder.end(),err2);
        int idx2 = std::distance(preorder.begin(),it2);
        preorder[idx1] = err2;
        preorder[idx2] = err1;
    }//辅助，在一个数组中找到两个值并将他们交换
    
    void change_tree(TreeNode* root, TreeNode* sample){
        if(root == NULL)    return;
        
        if(root->val != sample->val)    root->val = sample->val;

        change_tree(root->left,sample->left);
        change_tree(root->right,sample->right);
    }//把原树改成sample树

    void recoverTree(TreeNode* root) {
        Preorder(root,arr_preorder);
        Inorder(root, arr_inorder);
        fix_preorder(arr_preorder,arr_inorder);
        sort(arr_inorder.begin(),arr_inorder.end());
        TreeNode* sample_tree = buildTree(arr_preorder, arr_inorder);
        change_tree(root,sample_tree);
        }
};

————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

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

    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = new TreeNode(INT_MIN);

    void Inorder(TreeNode* root){
        if(root == NULL)    return;

        Inorder(root->left);

        if(first == NULL && prev->val > root->val) first = prev;
        if(first != NULL && prev->val > root->val)    second = root;
        prev = root;

        Inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        Inorder(root);
        swap(first->val, second->val);
    }
};
