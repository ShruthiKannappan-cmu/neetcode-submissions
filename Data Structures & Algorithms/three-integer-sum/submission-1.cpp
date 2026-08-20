class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        map<int,int> mp;
        int n = size(nums);
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
        }
        set<pair<int,int>> s;
        for(int i = 0;i<n;i++){
            for(int j= i+1;j<n;j++){
                int l = min(nums[i],nums[j]);
                int r = max(nums[i],nums[j]);
                s.insert({l,r});
            }
        }
        set<vector<int>> ss;
        for(auto x: s){
            int sum = x.first+x.second;
            mp[x.first]--;
            mp[x.second]--;

            if(mp[-sum]>0) {
                vector<int>v;
                v.push_back(x.first);
                v.push_back(x.second);
                v.push_back(-sum);
                sort(v.begin(),v.end());
                ss.insert(v);
            }
            mp[x.first]++;
            mp[x.second]++;
        }
        for(auto x: ss){
            ans.push_back(x);
        }
        return ans;
    }
};
