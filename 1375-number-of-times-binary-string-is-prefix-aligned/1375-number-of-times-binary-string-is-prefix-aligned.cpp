class Solution {
public:
    bool prefix(vector<char>& s,int x){
        int n=s.size();
        for(int i=0;i<=x;i++){
            if(s[i]!='1') return false;
        }
        for(int i=x+1;i<n;i++){
            if(s[i]!='0') return false;
        }
        return true;
    }
    int numTimesAllBlue(vector<int>& flips) {
        int n=flips.size();
        vector<bool> bit(n,false);
        int max=0,ans=0;
        for(int i=0;i<n;i++){
            bit[flips[i]-1]=true;
            while(max<n && bit[max]){
                max++;
            }
            ans+=max==i+1;
        }
        return ans;
    }
};