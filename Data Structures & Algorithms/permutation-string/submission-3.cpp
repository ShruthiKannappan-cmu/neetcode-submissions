class Solution {
public:
    bool checkValid(map<char,int> ms1){
        for(auto x: ms1){
            if(x.second!=0) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        map<char,int> ms1;
        int ns1 = s1.length();
        int ns2 = s2.length();
        if(ns2< ns1) return false;
        int s1sat = 0;
        int indl = 0;
        int indr = 0;
        for(int i= 0;i<ns1;i++){
            ms1[s1[i]]++;
        }
        for(;indr<ns1;indr++){
            if(ms1.find(s2[indr])!= ms1.end()){
                ms1[s2[indr]]--;   
            }
        }
        if(checkValid(ms1)) return true;
        while(indr<ns2){
            char cc = s2[indl];
            if(ms1.find(cc)!=ms1.end()){
                ms1[cc]++;
            }
            if(ms1.find(s2[indr])!= ms1.end()){
                ms1[s2[indr]]--;
            }
            if(checkValid(ms1)) return true;
            indr++;
            indl++;
        }
        return false;

    }
};
