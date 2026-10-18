class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode(){
        isEnd = false;
        for(int i = 0;i < 26;i++){
            children[i] = nullptr;
        }
    }
};

class Solution{
public:
    TrieNode* root = new TrieNode();

    void insert(string word){
        TrieNode* node = root;

        for(char ch : word){
            int idx = ch - 'a';

            if(node->children[idx] == nullptr){
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string word : wordDict){
            insert(word);
        }
        int n = s.size();
        vector<bool>dp(n+1,false);
        dp[0] = true;

        for(int i = 0;i<n;i++){
            if(!dp[i])continue;

            TrieNode* node = root;

            for(int j=i;j<n;j++){
                int idx = s[j] - 'a';

                if(node->children[idx] == nullptr){
                    break;
                }
                node = node->children[idx];

                if(node->isEnd){
                    dp[j+1] = true;
                }
            }
        }
        return dp[n];
    }
};