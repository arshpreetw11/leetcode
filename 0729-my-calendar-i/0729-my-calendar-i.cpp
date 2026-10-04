class MyCalendar {
public:
vector<vector<int>> intervals;
    MyCalendar() {
    }
    
    bool book(int startTime, int endTime) {
        if(intervals.size()==0){
            intervals.push_back({startTime,endTime});
            return true;
        }
        for(auto &in:intervals){
            int start=in[0];
            int end=in[1];
            if (!(endTime <= start || startTime >= end)) return false;
        }
        intervals.push_back({startTime,endTime});
        sort(intervals.begin(),intervals.end());
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */