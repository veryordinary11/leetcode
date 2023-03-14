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
    vector<int> record;

    void PathSum(TreeNode* root, int cursum){
        if(root->left == nullptr && root->right == nullptr){
            record.push_back(cursum);
            return;
        }
        if(root->left != nullptr){
            PathSum(root->left, cursum + root->left->val);
        }
        if(root->right != nullptr){
            PathSum(root->right, cursum + root->right->val);
        }
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        PathSum(root,root->val);
        if(find(record.begin(),record.end(),targetSum) != record.end()){
            return true;
        }
        return false;
    }
};

//先构造一个函数，把所有从根节点到叶子节点路径上的和存放到一个向量中
//在主函数中判断targer是否在向量中出现过即可
//辅助函数的写法利用递归：输入一个节点和一个int值代表直到遍历到当前节点所累加的和
//判断该节点是否为叶子节点，如果是，则直接存放后跳出，若不是，则递归遍历左右子树
