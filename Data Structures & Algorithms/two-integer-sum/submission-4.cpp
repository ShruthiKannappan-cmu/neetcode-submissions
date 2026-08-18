class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,vector<int>>mp;
        vector<int> ans;
        for(int i = 0;i<size(nums);i++){
            if(mp.find(nums[i])==mp.end()){
                vector<int> v;
                v.push_back(i);
                mp[nums[i]] = v;
            } else {
                mp[nums[i]].push_back(i);
            }
        }
        for(auto xx: mp){
            int x = xx.first;
            int y = target - x;
            if(y==x){
                if(size(mp[x])>1){
                    ans.push_back(mp[x][0]);
                    ans.push_back(mp[x][1]);
                    sort(ans.begin(),ans.end());
                    return  ans;
                } 
            } else {
                if(mp.find(y)!=mp.end()){
                    ans.push_back(xx.second[0]);
                    ans.push_back(mp[y][0]);
                    sort(ans.begin(),ans.end());
                    return  ans;
                }
            }

        }
        return ans;

    }
};
