class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int n = s.length();
        if(n<= 1) return n;
        int ans = 1;
        int l = 0, r = 0;
        mp[s[r]] = r;
        r++;
        while(r<n){
            if(mp.find(s[r]) != mp.end() && mp[s[r]] >= l){
                l = mp[s[r]]+1;
            } 
            mp[s[r]] = r;
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
