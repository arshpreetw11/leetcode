class Solution {
public:
    int hamming(string s1,string s2){
        int cnt=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                cnt++;
            }
        }
        return cnt;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        int n=words.size();
        vector<int> dp(n,1);
        vector<int> parent(n,-1);

        int best=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(groups[j]==groups[i]) continue;
                if(words[i].size()!=words[j].size()) continue;
                if(hamming(words[i],words[j])!=1) continue;

                if(dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }
            if(dp[i]>dp[best]){
                best=i;
            }
        }
        while(best!=-1){
            res.push_back(words[best]);
            best=parent[best];
        }
        reverse(res.begin(),res.end());
        return res;
    }
};