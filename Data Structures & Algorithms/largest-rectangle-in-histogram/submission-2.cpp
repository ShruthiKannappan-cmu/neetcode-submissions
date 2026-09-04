class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxVal = 0;
        stack<pair<int,int>> st;
        int n = heights.size();
        for(int i = 0;i<n;i++){
            int prev_ind = -1;
            int hi = heights[i];
            while(!st.empty() && st.top().first >= hi){
                prev_ind = st.top().second;
                st.pop();
            }
            if(prev_ind == -1){
                prev_ind = i;
            } 
            maxVal = max((i-prev_ind+1)*hi,maxVal);
            if(!st.empty()){
                maxVal = max(st.top().first*(i-st.top().second+1),maxVal);
            }
            st.push({hi,prev_ind});
        }
        while(!st.empty()){
            auto top_val = st.top();
            maxVal = max(maxVal,top_val.first * (n - top_val.second));
            st.pop();
        }
        return maxVal;
        
    }
};
