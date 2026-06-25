class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int m=votes[0].size();
        unordered_map<char,vector<int>> cnt;

        for (char c : votes[0])
            cnt[c] = vector<int>(m, 0);
        for(auto &vote:votes){
            for(int i=0;i<m;i++){
                cnt[vote[i]][i]++;
            }
        }
        string temp=votes[0];
        sort(temp.begin(),temp.end(),[&](char a ,char b){
            for(int i=0;i<m;i++){
                if(cnt[a][i]!=cnt[b][i]){
                    return cnt[a][i]>cnt[b][i];
                }
            }
            return a<b;
        });
        return temp;
    }
};