class Solution {
public:
    bool checkAlphanumeric(char c){
        if(c <='9' && c>= '0'){
            return true;
        }
        if(c<='Z' && c>= 'A') return true;
        if(c<='z' && c>= 'a') return true;
        return false;
    }
    char downcase(char c){
        if(c<='Z' && c>= 'A') return c+'a'-'A';
        return c;
    }
    bool isPalindrome(string s) {
        int r= s.length()-1;
        int length = s.length();
        int l = 0;
        while(r-l>0){
            while(r>=0 && !checkAlphanumeric(s[r])) r--;
            while(l<length && !checkAlphanumeric(s[l])) l++;
            char cl = downcase(s[l]);
            char cr = downcase(s[r]);
            if(cl!=cr) return false;
            l++;
            r--;
        }
        return true;
    }
};
