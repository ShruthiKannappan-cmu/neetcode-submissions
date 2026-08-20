class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(size(nums)==0) return 0;
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(int i = 0;i<size(nums);i++){
            int val = nums[i];
            if(mp.find(val-1)!=mp.end()){
                mp[val] = mp[val-1] +1;
            } else {
                mp[val] = 1;
            }
        }
        int ans = 1;
        for(auto x: mp){
            ans = max(ans,x.second);
        }
        return ans;
    }
};
