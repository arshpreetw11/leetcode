class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<vector<int>> pair;
        int n=aliceValues.size();
        for(int i=0;i<n;i++){
            int a=aliceValues[i];
            int b=bobValues[i];
            pair.push_back({a,b});
        }
        sort(pair.begin(),pair.end(),[&](vector<int> &a,vector<int>& b){
            return a[0]+a[1]>b[0]+b[1];
        });
        int alice=0;
        int bob=0;
        int i=0;
        for(auto &p:pair){
            int a=p[0];
            int b=p[1];
            if(i%2){
                bob+=b;
            }else{
                alice+=a;
            }i++;
        }
        if(alice>bob) return 1;
        else if(alice<bob) return -1;
        return 0;
    }
};