class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp = nums[0];
        int minp = nums[0];
        int ans = max(minp,maxp);
        for(int i = 1;i<nums.size();i++){
            int newmaxp = max(max(maxp*nums[i], minp * nums[i]), nums[i]);
            int newminp = min(min(minp*nums[i], maxp*nums[i]),nums[i]);

            maxp = newmaxp;
            minp = newminp;
            ans = max(maxp,ans);
            ans = max(ans,minp);
        }
        return ans;
    }
};
