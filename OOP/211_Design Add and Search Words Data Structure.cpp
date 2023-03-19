class Node{
public:
    bool is_word;
    unordered_map<char,Node*> children;

    Node(){
        is_word = false;
    }
};

class WordDictionary {
public:
    Node* root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(auto ch : word){
            if(node->children.find(ch) == node->children.end()){
                node->children[ch] = new Node();
            }
            node = node->children[ch];
        }
        node->is_word = true;
    }
    
    bool search_helper(Node* node, string word, int index){
        if(index == word.size())    return node->is_word;

        char ch = word[index];
        if(ch == '.'){
            for(auto& p : node->children){
                if(search_helper(p.second,word,index+1))   return true;
            }
            return false;
        }
        else{
            if(node->children.find(ch) == node->children.end()) return false;
            return search_helper(node->children[ch],word,index+1);
        }
    }

    bool search(string word) {
        return search_helper(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
