class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int n=arrivals.size();
        unordered_map<int,int> freq;
        vector<bool> remove(n,false);

        int ans=0;
        for(int i=0;i<n;i++){
            freq[arrivals[i]]++;
            if(i>=w && !remove[i-w]){
                freq[arrivals[i-w]]--;
            }
            if(freq[arrivals[i]]>m){
                remove[i]=true;
                freq[arrivals[i]]--;
                ans++;
            }
        }
        return ans;
    }
};