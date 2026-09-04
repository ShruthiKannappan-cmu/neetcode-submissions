class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int,int,greater<int>> mp;
        for(int i = 0;i<position.size();i++){
            if(mp.find(position[i])!=mp.end()){
                mp[position[i]] = min(mp[position[i]],speed[i]);
            } else {
                mp[position[i]] = speed[i];
            }
        }
    
        float timeVal = (target-mp.begin()->first)*1.0/(mp.begin()->second);
        int ans = 1;
        for(auto x: mp){
            float t = (target-x.first)*1.0/x.second;
            // cout<<x.first<<" "<<x.second<<endl;
            if( t > timeVal ){
                // cout<<"hello "<<x.first<<" "<<x.second<<endl;
                timeVal = t;
                ans++;
            }
            
        }
        return ans;
    }
};
