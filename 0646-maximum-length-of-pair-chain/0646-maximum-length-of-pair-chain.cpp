class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end(),[](vector<int>&a,vector<int>& b){
            return a[1]<b[1];
        });
        int len=0;
        int last=INT_MIN;
        for(auto &p: pairs){
            if(p[0]>last){
                len++;
                last=p[1];
            }
        }
        return len;
    }
};