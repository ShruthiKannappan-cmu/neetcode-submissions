class MinStack {
public:
    map<int, int> mp;
    stack<int>s;
    MinStack() {

    }
    
    void push(int val) {
        s.push(val);
        mp[val]++;
    }
    
    void pop() {
        int val = s.top();
        mp[val]--;
        if(mp[val]==0){
            mp.erase(val);
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        auto itr = mp.begin();
        return itr->first;
    }
};
