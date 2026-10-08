class Solution {
public:
    bool check(int capacity,vector<int> &weights,int days){
        int c=1;
        int w=0;
        for(int weight:weights){
            if(w+weight<=capacity){
                w+=weight;
            }else{
                c++;
                w=weight;
            }
        }
        return c<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0,high=0;
        for(int w:weights){
            low=max(low,w);
            high+=w;
        }
        while(low<high){
            int mid=low+(high-low)/2;

            if(check(mid,weights,days)){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};