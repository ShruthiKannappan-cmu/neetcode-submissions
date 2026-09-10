class PrefixTree {
    struct Node{
        map<char,Node*> mp;
        bool isEnd;
    };
    Node * nroot; 
public:
    PrefixTree() {
        nroot = new Node;
        nroot->isEnd = false;
    }
    Node * insertChar(Node * root, char c, bool isEnd){
        if((root->mp).find(c) == (root->mp).end()){
            (root->mp)[c] = new Node;
            (root->mp)[c]->isEnd = false;
        } 
        (root->mp)[c]->isEnd|=isEnd;
        // cout<<"insert "<<c<<" "<<(root->mp)[c]<<" "<<isEnd<<endl;
        return (root->mp)[c];
    }
    void insert(string word) {
        auto cur_root = nroot;
        for(int i = 0;i<word.length()-1;i++){
            cur_root = insertChar(cur_root,word[i], false);
        }
        cur_root = insertChar(cur_root,word[word.length()-1], true);
    }

    pair<Node*,bool> searchChar(Node * root, char c, bool isEnd){
        if((root->mp).find(c) == (root->mp).end()){
            // cout<<"Not found "<<c<<endl;
            return {NULL,false};
        } 
        if(isEnd) {
            if(!((root->mp)[c]->isEnd)) {
                // cout<<"Not end "<<c<<" " <<(root->mp)[c]->isEnd<<endl;
                return {NULL,false};
        }}
        return {(root->mp)[c],true};
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
