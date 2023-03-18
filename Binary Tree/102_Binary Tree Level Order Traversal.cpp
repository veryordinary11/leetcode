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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)    return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int helper = q.size();
            for(int i = 0; i < helper; i++){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            result.push_back(temp);
        }
        return result;
    }
};

//借助队列BFS遍历树，从而得到层序遍历序列
//关键在于，当用BFS遍历树的时候，返回的是单vector，本题要返回嵌套vector以此来反映出树的层次关系
//解决方法是在while循环中嵌套一个for循环，for的循环次数是q.size()，即队列中储存的当前层次的节点数量
//一个细节是，for条件中，因为循环体操作会改变q的size，所以1.要么引入一个新变量存放当前的size 2.要么int i = q.size; i > 0 ;i--;
