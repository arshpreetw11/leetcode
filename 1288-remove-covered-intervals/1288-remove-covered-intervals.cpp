class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        int n=in.size();
        sort(in.begin(),in.end(),[&](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]) return a[1]<=b[1];
            return a[0]>b[0]; 
        });
        int rem=0;
        for(int i=0;i<n;i++){
            int a=in[i][0];
            int b=in[i][1];
            for(int j=i+1;j<n;j++){
                int c=in[j][0];
                int d=in[j][1];
                if(c<=a && b<=d){
                    rem++;
                    break;
                }
            }
        }
        return n-rem;
    }
};