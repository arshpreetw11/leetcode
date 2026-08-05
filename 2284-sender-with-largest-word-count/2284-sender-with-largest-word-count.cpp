class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n=senders.size();
        unordered_map<string,int> total;
        for(int i=0;i<n;i++){
            string sen=messages[i];
            int cnt=1;
            for(char ch: sen){
                if(ch==' '){
                    cnt++;
                }
            }
            total[senders[i]]+=cnt;
        }

        int mx=0;
        string ans="";
        for(auto &[s,c]:total){
            if(mx==c && ans<s){
                ans=s;
            }
            if(mx<c){
                ans=s;
                mx=c;
            }
        }
        return ans;
        
    }
};