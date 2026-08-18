class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        for(auto x: nums){
            freq[x]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        for(auto x : freq){
            pq.push({x.second,x.first});
        }
        vector<int> ans;
        while(k--){
            auto e = pq.top();
            pq.pop();
            ans.push_back(e.second);
        }
        return ans;
    }
};
