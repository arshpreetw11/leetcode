class TimeMap {
public:
unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()) return "";

        const auto &vec=mp[key];
        auto it = upper_bound(vec.begin(), vec.end(), timestamp, [](int t, const pair<int, string>& p) {
                    return t < p.first;
                });        
        if(it==vec.begin()) return "";

        return (it-1)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */