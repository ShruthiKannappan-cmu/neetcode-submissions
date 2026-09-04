class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int,int> mp;
        for(int i = 0;i<position.size();i++){
            if(mp.find(position[i])!=mp.end()){
                mp[position[i]] = min(mp[position[i]],speed[i]);
            } else {
                mp[position[i]] = speed[i];
            }
        }
        map<int, float,greater<int>> time_to_reach;;
        for(auto x: mp){
            float t = (target-x.first)*1.0/x.second;
            time_to_reach[x.first] = t;
        }
        stack<float> ss;
        for(auto x: time_to_reach){
            if(ss.empty() || (ss.top() < x.second)){
                ss.push(x.second);
            }
        }
        return ss.size();
    }
};
