class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=0;
        int ans=0;

        for(string &row: bank){
            int curr=0;
            for(char ch : row){
                if(ch=='1'){
                    curr++;
                }
            }
            if(curr==0) continue;
            ans+=curr*prev;
            prev=curr;
        }
        return ans;
    }
};