class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int>res(temperatures.size());
        for(int i = 0;i<temperatures.size();i++){
            while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                int ind = st.top();
                res[ind] = i-ind;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            int ind = st.top();
            res[ind] = 0;
            st.pop();
        }
        return res;
    }
};
