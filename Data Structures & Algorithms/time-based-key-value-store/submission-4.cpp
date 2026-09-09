class TimeMap {

private:
    map<pair<string,int>,string>mp;
public:
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[{key,timestamp}] = value;
    }
    
    string get(string key, int timestamp) {
        auto itr = mp.upper_bound({key,timestamp});
        // for(auto x: mp){
        //     cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;
        // }
        // if(itr == mp.end()) itr--;
        if(itr!=mp.begin())itr--;
        if((itr!=mp.end()) && (itr->first).first == key && (itr->first).second <= timestamp) 
                return itr->second;
        return "";
        }
        
        
};
