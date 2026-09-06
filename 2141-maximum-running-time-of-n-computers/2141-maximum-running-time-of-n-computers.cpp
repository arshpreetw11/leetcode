class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        
        int sz=batteries.size();
        long long total=0;
        for(int b:batteries){
            total+=b;
        }
        long long low=0,high=total/n;
        while(low<=high){
            long long x=(low+high)/2;
            long long available=0;
            for(int b:batteries){
                available+=min((long long)b,x);
            }
            if(available>=n*x){low=x+1;}
            else high=x-1;
        }return high;
    }
};