class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0,ans=0;
        sort(tokens.begin(),tokens.end());
        int n=tokens.size();
        int i=0;
        int j=n-1;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score++;
                ans=max(ans,score);
                i++;
            }
            else if(score>0){
                power+=tokens[j];
                score--;
                j--;
            }else{
                break;
            }
        }
        return ans;
    }
};