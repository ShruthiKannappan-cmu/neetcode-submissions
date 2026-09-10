class KthLargest {
    int kval;
    multiset<int>s;
public:
    KthLargest(int k, vector<int>& nums) {
        kval = k;
        for(auto x: nums){
            if(s.size() < kval){
                s.insert(x);
            } else {
                if(*s.begin() < x){
                    // cout<<"init Removing "<<*s.begin()<<endl;
                    s.erase(s.begin());
                    s.insert(x);
                }
            }
        }
    }
    
    int add(int val) {
        if(s.size() < kval){
                s.insert(val);
        } else {
                if(*s.begin() < val){
                    // cout<<"Removing "<<*s.begin()<<endl;
                    s.erase(s.begin());

                    s.insert(val);
                }
        }
        return *s.begin();
    }
};
