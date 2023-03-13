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
    void Inorder(TreeNode* root, vector<int>& ar){
        if(!root)   return;
        Inorder(root->left,ar);
        ar.push_back(root->val);
        Inorder(root->right,ar);
    }//中序遍历

    bool isSymmetric(TreeNode* root) {
        vector<int> ar;
        Inorder(root,ar);
        if(ar.size() == 1)  return true;
        for(int i = 0; i < ar.size()/2; i++){
            if(ar[i] != ar[ar.size()-1-i]){
                return false;
                break;
            }
        }
        return true;
    }
};

//一开始我想用中序遍历的方法做这道题，因为我发现对称的二叉树的中序遍历序列是回文的
//但是后来发现这不是充要条件，一些不对称的二叉树的中序遍历序列也是回文的
//于是我想用特殊值来表示遍历过程中遇到的空节点，但是这种方法好像并不能解决一些不对称的二叉树遍历序列也是回文的结果

________________________________________________________________________________________________________________________

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

    bool isSymmetricHelper(TreeNode* left, TreeNode* right){
        if((left == nullptr && right != nullptr) || (left != nullptr && right == nullptr))  return false;
        if(left == nullptr && right == nullptr) return true;

        if(left->val != right->val) return false;
        else{
            return isSymmetricHelper(left->left,right->right) && isSymmetricHelper(left->right,right->left);
        }
    }

    bool isSymmetric(TreeNode* root) {
        return isSymmetricHelper(root->left,root->right);
    }
};

//判断跟节点的左子树和右子树是否对称 1 根节点值相等 2 左子树的左子树和右子树的右子树相等 左子树的右子树和右子树的左子树相等
//在Helper中，如果两个树其中一个非空而另一个为空，则不可能相等，返回false
//如果都为空，则相等，返回true
//如果都非空，但是根节点的值不等，则不相等，返回false
//再递归比较左子树的左子树和右子树的右子树 && 左子树的右子树和右子树的左子树是否相等
