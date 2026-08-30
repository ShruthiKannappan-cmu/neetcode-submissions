class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> dpl(n);
        vector<int> dpr(n);
        dpl[0] = height[0];
        for(int i = 1;i<n;i++){
            dpl[i] = max(dpl[i-1],height[i]);
        }
        dpr[n-1] = height[n-1];
        for(int i = n-2;i>=0;i--){
            dpr[i] = max(dpr[i+1], height[i]);
        }

        int sum = 0;
        for(int i = 0;i<n;i++){
            sum+= min(dpl[i],dpr[i]) - height[i];
        }
        return sum;
    }
};
