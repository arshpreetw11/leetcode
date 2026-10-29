class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        vector<int> count1(n,0),count0(n,0);
        for(int i=0,cnt=0;i<n;i++){
            count1[i]=cnt;
            if(s[i]=='1') cnt++;
        }
        for(int i=n-1,cnt=0;i>=0;i--){
            count0[i]=cnt;
            if(s[i]=='0') cnt++;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,count1[i]+count0[i]);
        }
        return ans;
    }
};