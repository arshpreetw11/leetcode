class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        int ans=0,suffix=0;
        for(int i=n-1;i>=0;i--){
            suffix+=satisfaction[i];
            if(suffix<0) break;
            ans+=suffix;
        }
        return ans;
    }
};