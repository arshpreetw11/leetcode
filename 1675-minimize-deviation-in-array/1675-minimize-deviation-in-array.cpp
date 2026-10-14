class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int> pq;
        int mn=INT_MAX;
        for(int x:nums){
            if(x%2) {
                mn=min(mn,2*x);
                pq.push(2*x);
            }
            else{
                mn=min(mn,x);
                pq.push(x);
            }
        }
        int mx=0;
        int diff=INT_MAX;
        
        while(true){
            int t=pq.top();
            pq.pop();
            diff=min(diff,t-mn);
            
            if(t%2) break;
            t/=2;
            mn=min(mn,t);
            pq.push(t);
        }
        return diff;
    }
};