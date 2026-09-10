class WordDictionary {
    struct Node{
        Node* mp[26];
        bool isEnd;
    };
    Node * nroot; 
public:
    WordDictionary() {
        nroot = new Node;
        for(int i = 0;i<26;i++){
            nroot->mp[i] = NULL;
        }
        nroot->isEnd = false;
    }
    Node * insertChar(Node * root, char c, bool isEnd){
        if((root->mp)[c-'a'] == NULL){
            (root->mp)[c-'a'] = new Node;
            for(int i = 0;i<26;i++){
                (root->mp)[c-'a']->mp[i] = NULL;
            }
            (root->mp)[c-'a']->isEnd = false;
        } 
        (root->mp)[c-'a']->isEnd|=isEnd;
        return (root->mp)[c-'a'];
    }
    
    void addWord(string word) {
        // return;
        auto cur_root = nroot;
        for(int i = 0;i<word.length()-1;i++){
            cur_root = insertChar(cur_root,word[i], false);
        }
        cur_root = insertChar(cur_root,word[word.length()-1], true);
    }
    bool searchsuffix(string word, int i, Node * root) {
        if(root == NULL) return false;
        if(i == word.length()) {
            return root->isEnd;
        }
        bool foundSuffix = false;
        if(word[i] == '.'){
            for(int j = 0;j<26;j++){
                if((root->mp)[j]!= NULL){
                    foundSuffix|=searchsuffix(word, i+1,(root->mp)[j]);
                }
            }
        } else {
            if((root->mp)[word[i]-'a']!= NULL){
                foundSuffix|=searchsuffix(word, i+1,(root->mp)[word[i]-'a']);
            }
        }
        return foundSuffix;
    }
    bool search(string word) {
        // return true;
        return searchsuffix(word, 0, nroot);
    }
};
