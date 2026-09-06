class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low=0;
        long long high=1LL*(*min_element(time.begin(),time.end()))*totalTrips;

        while(low<=high){
            long long x=(low+high)/2;
            long long trips=0;
            for(int t:time){
                trips+=x/t;
            }
            if(trips>=totalTrips){
                high=x-1;
            }else low=x+1;
        }return low;
    }
};