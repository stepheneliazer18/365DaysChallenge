class FreqStack {
public:
    int maxi = 0;
    map<int,int> freq;
    map<int,vector<int>> mp;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        
        mp[freq[val]].push_back(val);
        
        maxi = max(maxi,freq[val]);
        
    }
    
    int pop() {
        int res = mp[maxi].back();
        freq[res]--;
        mp[maxi].pop_back();
        if(mp[maxi].size() == 0) maxi--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */