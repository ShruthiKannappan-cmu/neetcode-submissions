class Solution {
public:
    int numDecodingsDP(string &s,vector<int> &dp, int i){
        int n = s.length();
        if(i>=n) return 1;
        if(dp[i]!=-1 ) return dp[i];
        if(s[i] == '0') return dp[i] = 0;
        dp[i] = numDecodingsDP(s,dp,i+1);
        if(i+1 < n){
            int val = stoi(s.substr(i,2));
            if((val>= 1) && (val <= 26)){
                dp[i]+= numDecodingsDP(s,dp,i+2);
            }
        }
        return dp[i];
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n);
        for(int i = 0;i<n;i++) dp[i] = -1;
        int ans = numDecodingsDP(s,dp, 0);
        // for(int i = 0;i<n;i++){
        //     cout<<dp[i]<<endl;
        // }
        return ans;
    }
};
