class RecentCounter {
public:
    vector<int> records;
    int c=0;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        records.push_back(t);
        while(records[c]<t-3000) c++;
        return records.size()-c;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */