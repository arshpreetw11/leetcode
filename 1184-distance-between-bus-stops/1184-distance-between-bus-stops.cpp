class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n=distance.size();
        int sum1=0;
        int sum2=0;
        if(start>destination) swap(start,destination);

        for(auto i=0;i<n;++i){
            if(i>=start && i<destination) sum1+=distance[i];
            else sum2+=distance[i];
        }
        return min(sum1,sum2);
    }
};