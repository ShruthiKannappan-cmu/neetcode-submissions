class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = size(nums);
        int dpr[n];
        int dpl[n];
        dpl[0] = nums[0];
        for(int i = 1;i<n;i++){
            dpl[i] = dpl[i-1]*nums[i];
        }
        dpr[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            dpr[i] = dpr[i+1]*nums[i];
        }
        vector<int> v(n);
        for(int i = 0;i<n;i++){
            v[i] = 1;
            if(i-1>=0){
                v[i]*= dpl[i-1];
            }
            if(i+1<n){
                v[i]*= dpr[i+1];
            }
        }
        return v;
    }
};
