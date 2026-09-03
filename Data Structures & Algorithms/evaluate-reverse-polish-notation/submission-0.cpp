class Solution {
public:
     bool isOp(string t){
        if(t == "+" || t == "-" || t == "*" || t == "/" )
                return true;
                return false;

     }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto t: tokens){
            if(!isOp(t)) {
                st.push(stoi(t));
            } else {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int ans;
                if(t == "+"){
                 ans = a+b;
            } else if(t == "-"){
                ans = a-b;
            } else if(t == "*"){
                ans = a*b;
            } else if(t == "/"){
                ans = a/b;
            } 
            st.push(ans);
            }

        }
        return st.top();
    }
};
