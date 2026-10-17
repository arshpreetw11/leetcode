class MyCalendarTwo {
public:
vector<pair<int,int>> booked,doubly;

    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        for (auto &it : doubly) {
            if (max(startTime, it.first) < min(endTime, it.second)) {
                return false;
            }
        }

        for(auto &it: booked){
            int s=max(startTime, it.first);
            int e=min(endTime, it.second);

            if(s<e){
                doubly.push_back({s,e});
            }
        }
        booked.push_back({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */