class Trie {
public:
    Trie* children[26];
    bool isEnd;
    Trie() {
        for(int i = 0;i < 26;i++){
            children[i] = nullptr;
        }
        isEnd = false;
    }
    
    void insert(string word) {
        Trie* node = this;
        for(char ch : word){
            int index = ch - 'a';
            if(node->children[index] == nullptr){
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;

        for(char ch : word){
            int index = ch - 'a';

            if(node->children[index] == nullptr){
                return false;
            }
            node = node->children[index];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;

        for(char ch : prefix){
            int index = ch - 'a';
            if(node->children[index] == nullptr){
                return false;
            }
            node = node->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */