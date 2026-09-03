class Solution {
public:
    bool isopenbracket(char c){
        if(c == '(' || c == '[' || c== '{') return true;
        return false;
    }
    bool isPair(char a, char b){
        if( a == '[' && b == ']') return true;
        if( a == '(' && b == ')') return true;
        if( a == '{' && b == '}') return true;
        return false;

    }
    bool isValid(string s) {
        stack<char> st;
        for(auto c: s){
            if(isopenbracket(c)) st.push(c);
            else {
                if(st.empty()) return false;
                if(!isPair(st.top(),c)) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
