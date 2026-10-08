class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int> prefix(n-1,0),suffix(n-1,0);
        prefix[0]=values[0]+0;
        for(int i=1;i<n-1;i++){
            prefix[i]=max(prefix[i-1],values[i]+i);
        }
        suffix[n-2]=values[n-1]-(n-1);
        for(int i=n-3;i>=0;i--){
            suffix[i]=max(suffix[i+1],values[i+1]-(i+1));
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans=max(ans,prefix[i]+suffix[i]);
        }
        return ans;
    }
};