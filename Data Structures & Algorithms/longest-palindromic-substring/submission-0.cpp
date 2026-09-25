class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n);
        for(int i = 0;i<n;i++){
            vector<bool>v(n);
            dp[i] = v;
        }
        for(int i = 0;i<n;i++){
            dp[i][i] = true;
        }
        for(int i = 0;i<n-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
            } else {
                dp[i][i+1] = false;
            }
        }
        for(int k = 2;k<n;k++){
            for(int i = 0;i<n-k;i++){
                int j = i+k;
                
                if((s[i] == s[j]) && dp[i+1][j-1]){
                    dp[i][j] = true;
                } else {
                    dp[i][j] = false;
                }
            }
        }
        // for(int i = 0;i<n;i++){
        //     for(int j = 0;j<n;j++){
        //         cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;;
        //     }
        // }
        int indi = -1, indj = -1;
        for(int k = n-1;k>=0;k--){
            for(int i = 0;i<n-k;i++){
                int j = i+k;
                // cout<<"hello " <<i<<" "<<j<<" "<<dp[i][j]<<endl;;
                if(dp[i][j]){
                    indi = i;
                    indj = j;
                    break;
                }
            }
            if(indi!=-1) break;
        }
        // cout<<indi<<" "<<indj<<endl;
        return s.substr(indi,indj-indi+1);
    }
};
