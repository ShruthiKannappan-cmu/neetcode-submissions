class PrefixTree {
    struct Node{
        Node* mp[26];
        bool isEnd;
    };
    Node * nroot; 
public:
    PrefixTree() {
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
        // cout<<"insert "<<c<<" "<<(root->mp)[c]<<" "<<isEnd<<endl;
        return (root->mp)[c-'a'];
    }
    void insert(string word) {
        auto cur_root = nroot;
        for(int i = 0;i<word.length()-1;i++){
            cur_root = insertChar(cur_root,word[i], false);
        }
        cur_root = insertChar(cur_root,word[word.length()-1], true);
    }

    pair<Node*,bool> searchChar(Node * root, char c, bool isEnd){
        if((root->mp)[c-'a'] == NULL){
            // cout<<"Not found "<<c<<endl;
            return {NULL,false};
        } 
        if(isEnd) {
            if(!((root->mp)[c-'a']->isEnd)) {
                // cout<<"Not end "<<c<<" " <<(root->mp)[c]->isEnd<<endl;
                return {NULL,false};
        }}
        return {(root->mp)[c-'a'],true};
    }
    
    bool search(string word) {
        auto cur_root = nroot;
        for(int i = 0;i<word.length()-1;i++){
            auto res = searchChar(cur_root,word[i], false);
            // cout<<"char "<<word[i]<<" res "<<res.first<<" "<<res.second<<endl;
            if(!res.second) return false;
            cur_root = res.first;
        }
        auto res = searchChar(cur_root,word[word.length()-1], true);
        // cout<<"last char "<<word[word.length()-1]<<" res "<<res.first<<" "<<res.second<<endl;
        return res.second;
    }
    
    bool startsWith(string prefix) {
        auto cur_root = nroot;
        for(int i = 0;i<prefix.length();i++){
            auto res = searchChar(cur_root,prefix[i], false);
            if(!res.second) return false;
            cur_root = res.first;
        }
        return true;
    }
};
