class Solution {
public:
    int kSimilarity(string s1, string s2) {
        int n=s1.size();
        if(s1==s2) return 0;
        unordered_set<string> vis;
        queue<string> q;
        q.push(s1);
        vis.insert(s1);
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string curr=q.front();
                q.pop();

                if(curr==s2){
                    return level;
                }
                int i=0;
                while(i<curr.size() && curr[i]==s2[i]){
                    i++;
                }
                for(int j=i+1;j<curr.size();j++){
                    if(curr[j]!=s2[i]) continue;
                    if(curr[j]==s2[j]) continue;
                    swap(curr[i],curr[j]);
                    if(!vis.count(curr)){
                        vis.insert(curr);
                        q.push(curr);
                    }
                    swap(curr[i],curr[j]);
                }
                
            }
            level++;
        }
        return level;
    }
};