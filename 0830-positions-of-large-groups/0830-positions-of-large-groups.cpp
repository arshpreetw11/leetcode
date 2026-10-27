class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int i=0;
        int n=s.size();
        vector<vector<int>> res;
        while(i<n){
            int j=i;
            while(j<n && s[i]==s[j]){
                j++;
            }

            int len=j-i;
            if(len>=3){
                res.push_back({i,j-1});
            }
            i=j;
        }
        return res;
    }
};