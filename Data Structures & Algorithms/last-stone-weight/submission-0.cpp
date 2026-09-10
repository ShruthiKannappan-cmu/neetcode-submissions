class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>> pq;
        for(auto x: stones){
            pq.push(x);
        }
        while(pq.size()>1){
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();
            if(top1 == top2){
                continue;
            } else {
                pq.push(abs(top1-top2));
            }
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};
