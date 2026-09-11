class TweetCounts {
public:
    struct Tweet{
        string tweet;
        int time;
    };
    unordered_map<string,vector<int>> tweet;
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        tweet[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int intervals;
        if(freq=="minute")
            intervals=60;
        else if(freq=="hour")
            intervals=3600;
        else 
            intervals=86400;
        
        int chunks=(endTime-startTime)/intervals +1;
        vector<int> ans(chunks,0);
        for(int t: tweet[tweetName]){
            if(t>=startTime && t<=endTime){
            int idx=(t-startTime)/intervals;
            ans[idx]++;}
        }
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */