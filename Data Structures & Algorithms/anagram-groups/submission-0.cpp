class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        for(auto s: strs){
            string sorted_string = s;
            sort(sorted_string.begin(), sorted_string.end());
            if(mp.find(sorted_string) == mp.end()){
                vector<string> v;
                v.push_back(s);
                mp[sorted_string] = v;
            } else {
                mp[sorted_string].push_back(s);
            }
        }
        vector<vector<string>> ans;
        for(auto x: mp){
            vector<string> v;
            for(auto s: x.second){
                v.push_back(s);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
