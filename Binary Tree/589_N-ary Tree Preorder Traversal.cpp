/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void preorder_helper(Node* root,vector<int>& arr){
        arr.push_back(root->val);
        if(root->children.empty()) return;
        for(int i = 0; i < root->children.size(); i++){
            preorder_helper(root->children[i],arr);
        }
        
    }

    vector<int> preorder(Node* root) {
        if(root == NULL)    return {};
        vector<int> arr;
        preorder_helper(root,arr);
        return arr;
    }

};
