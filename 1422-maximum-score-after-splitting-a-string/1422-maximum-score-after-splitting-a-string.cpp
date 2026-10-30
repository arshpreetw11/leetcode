class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        vector<int> prefix(n,0),suffix(n,0);
        prefix[0]=(s[0]=='0')?1:0;
        suffix[n-1]=(s[n-1]=='1')?1:0;

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+(s[i]=='0'?1:0);
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+(s[i]=='1'?1:0);
        }

        int mx=0;
        for(int i=0;i<n-1;i++){
            int sum=prefix[i]+suffix[i+1];
            mx=max(mx,sum);
        }
        return mx;
    }
};