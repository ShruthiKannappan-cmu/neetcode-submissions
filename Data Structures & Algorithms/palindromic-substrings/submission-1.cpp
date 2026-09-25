class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> ispal;
        for(int i = 0;i<n;i++){
            vector<bool> v2(n);
            ispal.push_back(v2);
        }
        for(int i = 0;i<n;i++){
            ispal[i][i] = true;
        }
        for(int i = 0;i<n-1;i++){
            if(s[i] == s[i+1]) {ispal[i][i+1]= true;}
            else {
                ispal[i][i+1]= false;
            }
        }
        for(int k = 2;k<n;k++){
            for(int i = 0;i<n-k;i++){
               int j = i+k;
               if(s[i] == s[j] && ispal[i+1][j-1]){
                    ispal[i][j] = true;
                } else {
                    ispal[i][j] = false;
                }
            }
        }
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                if(ispal[i][j]) cnt++;
            }   
        }
        return cnt;
        
    }
};
