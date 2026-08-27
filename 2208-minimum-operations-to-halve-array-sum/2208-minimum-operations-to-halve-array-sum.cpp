class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum=0;
        priority_queue<double> pq;
        for(int x:nums){
            sum+=x;
            pq.push(x);
        }
        //sort(nums.begin(),nums.end());
        //priority_queue;;
        
        double newSum=sum;
        int op=0;
        while(newSum>sum/2){
            double val=pq.top();
            pq.pop();
            newSum-=val/2.0;
            pq.push(val/2.0);
            op++;
        }
        return op;
    }
};