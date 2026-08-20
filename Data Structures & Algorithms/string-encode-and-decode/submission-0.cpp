class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto s: strs){
            string length_str = to_string(s.length());
            while(length_str.length()<3){
                length_str = "0"+length_str;
            }
            ans+= length_str + s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int ind = 0;
        while(ind<s.length()){
            string length_str = s.substr(ind,3);
            int length = stoi(length_str);
            ind+=3;
            string str = s.substr(ind,length);
            ans.push_back(str);
            ind+= length;
        }
        return ans;
    }
};
