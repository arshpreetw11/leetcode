class Solution {
public:
int dp[11][1<<10][2];
    int dfs(string s,int pos,int mask,bool tight,bool started){
        
        if(pos==s.size()){
            return started;
        }
        if(!tight &&  dp[pos][mask][started]!=-1) 
            return dp[pos][mask][started];

        int limit=tight?s[pos]-'0':9;
        int ans=0;
        for(int d=0;d<=limit;d++){
            if(!started && d==0){
                ans+=dfs(s,pos+1,mask,tight && d==limit,false);
            }
            else{
                if(mask & (1<<d)){
                    continue;
                }
                ans+=dfs(s,pos+1,mask|(1<<d),tight && d==limit,true);
            }
        }
        if (!tight)
            dp[pos][mask][started] = ans;
        return ans;
    }
    int countSpecialNumbers(int n) {
        if(n<=10) return n;
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return dfs(s,0,0,true,false);
    }
};