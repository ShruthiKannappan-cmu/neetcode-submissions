class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
int m = size(strs);
        int freq[26] = {0};
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(int i = 0;i<m;i++){
            string s = strs[i];
            fill(std::begin(freq), std::end(freq), 0); 
            for(auto c: s){
                int k = c-'a';
                freq[k]++;
            }
            string freq_s = "";
            for(int i = 0;i<26;i++){
                char c = 'a'+i;
                freq_s.push_back(c);
                freq_s += to_string(freq[i]);
            }
            if(mp.find(freq_s) == mp.end()){
                vector<string> v;
                v.push_back(s);
                mp[freq_s] = v;
            } else {
                mp[freq_s].push_back(s);
            }
        }
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
