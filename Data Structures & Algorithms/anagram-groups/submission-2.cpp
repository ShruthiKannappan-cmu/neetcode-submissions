class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int m = size(strs);
        map<vector<int>, vector<string>> mp;
        vector<vector<string>> ans;
        for(int i = 0;i<m;i++){
            string s = strs[i];
            vector<int>v(26,0);
            for(auto c: s){
                v[c-'a']++;
            }
            if(mp.find(v) == mp.end()){
                vector<string> vv;
                vv.push_back(s);
                mp[v] = vv;
            } else {
                mp[v].push_back(s);
            }
        }
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
