class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) return tasks.size();
        int totalInterval = 0;
        map<char,int> mp;
        for(auto x: tasks) mp[x]++;
        priority_queue<pair<int,char>,vector<pair<int,char>>> pq;
        for(auto p: mp){
            pq.push({p.second,p.first});
        }
        while(!pq.empty()){
            set<pair<int,char>>s;
            int t  = min(n+1,(int)pq.size());
            int t1 = t;
            while(t--){
                auto topVal = pq.top();
                pq.pop();
                topVal.first--;
                if(topVal.first > 0){
                    s.insert(topVal);
                }
            }
            for(auto x: s){
                pq.push(x);
            }
            int idlecnt = n+1 - t1;
            totalInterval+=t1;
            // cout<<t1<<endl;;
            if(!pq.empty()) totalInterval+=idlecnt;
        }
        return totalInterval;
    }
};
