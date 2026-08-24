class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxW = 0;
        int n = size(heights);
        int l = 0, r = n-1;
        while(r-l>0){
            int hl = heights[l];
            int hr = heights[r];
            if(hl<= hr){
                maxW = max(maxW, hl*(r-l));
                l++;
            } else {
                maxW = max(maxW, hr*(r-l));
                r--;
            }
        }
        return maxW;
    }
};
