class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.size();
        vector<int> ans(n,0);
        vector<int> indices;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch==c) 
                indices.push_back(i);
        }
        for(int i=0;i<n;i++){
            int mn=INT_MAX;
            if(s[i]==c){
                continue;
            }
            for(int idx:indices){
                mn=min(mn,abs(i-idx));
            }
            ans[i]=mn;
        }
        return ans;
    }
};