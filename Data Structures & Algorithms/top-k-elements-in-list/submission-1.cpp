class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int n = size(nums);
        vector<int> ans;
        for(auto x: nums){
            freq[x]++;
        }
        unordered_map<int,vector<int>> rev_freq;
        for(auto x: freq){
            rev_freq[x.second].push_back(x.first);
        }
        for(int f = n;f>0;f--){
            for(auto x: rev_freq[f]){
                k--;
                ans.push_back(x);
                if(k==0) break;
            }
            if(k==0) break;
        }
        return ans;
    }
};
