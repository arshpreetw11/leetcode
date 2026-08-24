class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int dbl=changed.size();
        if(dbl%2) return {};
        int n=dbl/2;
        unordered_map<int,int> freq;
        for(int x:changed){
            freq[x]++;
        }
        vector<int> ans;
        sort(changed.begin(),changed.end());
        for(int x:changed){
            if(freq[x]==0) continue;
            if(freq[2*x]==0){
                return {};
            }
            ans.push_back(x);
            freq[x]--;
            freq[2*x]--;
        }
        return ans;
    }
};