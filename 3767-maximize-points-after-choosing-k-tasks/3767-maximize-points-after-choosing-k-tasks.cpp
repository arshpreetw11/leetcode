class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        
        long long reward1=0;
        int n=technique1.size();
        for(int t:technique1){
            reward1+=t;
        }
        vector<int> delta;
        for(int i=0;i<n;i++){
            int diff=technique2[i]-technique1[i];
            if(diff>0)
            delta.push_back(diff);
        }
        sort(delta.begin(),delta.end(),greater<int>());
        int limit=min(n-k,(int)delta.size());

        for(int i=0;i<limit;i++){
            reward1+=delta[i];
        }
        return reward1;
    }
};