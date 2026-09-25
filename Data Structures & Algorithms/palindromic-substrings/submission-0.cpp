class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> dp;
        vector<vector<bool>> ispal;
        for(int i = 0;i<n;i++){
            vector<int> v(n);
            vector<bool> v2(n);
            dp.push_back(v);
            ispal.push_back(v2);
        }
        for(int i = 0;i<n;i++){
            dp[i][i] = 1;
            ispal[i][i] = true;
        }
        for(int i = 0;i<n-1;i++){
            dp[i][i+1] = 2;
            if(s[i] == s[i+1]) {dp[i][i+1]++; ispal[i][i+1]= true;}
            else {
                ispal[i][i+1]= false;
            }
        }
        for(int k = 2;k<n;k++){
            for(int i = 0;i<n-k;i++){
               int j = i+k;
               dp[i][j] = dp[i][j-1]+dp[i+1][j] - dp[i+1][j-1];
               if(s[i] == s[j] && ispal[i+1][j-1]){
                    ispal[i][j] = true;
                    dp[i][j]++;
                }
            }
        }
        return dp[0][n-1];
        
    }
};
