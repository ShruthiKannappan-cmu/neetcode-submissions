class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        map<int,vector<pair<int,int>>> mp;
        for(auto pp: points ){
            int x = pp[0];
            int y = pp[1];
            int d = x*x + y*y;
            mp[d].push_back({x,y});
        }
        int cnt = 0;
        for(auto pp: mp){
            for(auto p: pp.second){
                cnt++;
                int x = p.first;
                int y = p.second;
                vector<int> v(2);
                v[0] = x;
                v[1] = y;
                ans.push_back(v);
                if(cnt == k) return ans;
            }
        }
        return ans;
    }
};
