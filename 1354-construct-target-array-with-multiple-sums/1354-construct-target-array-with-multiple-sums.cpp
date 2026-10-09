class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long> pq;
        long long sum=0;
        for(int n:target){
            pq.push(n);
            sum+=n;
        }
        
        while(true){
            long long t=pq.top();
            pq.pop();
            
            long long sub=sum-t;
            if(sub==0) return t==1;
            if(sub==1) return true;
            if(t==1) return true;
            if(t<=sub) return false;
            long long prev=t%sub;
            if(prev==0) return false;
            pq.push(prev);
            sum=sub+prev;
        }
        return true;
    }
};