class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<vector<int>> vl;
        int n=values.size();
        for(int i=0;i<n;i++){
            vl.push_back({labels[i],values[i]});
        }
        sort(vl.begin(),vl.end(),[&](auto& a,auto& b){
            return a[1]>b[1];
        });
        int sum=0;
        int picked=0;
        unordered_map<int,int> cnt;
        for(int i=0;i<n;i++){
            int lb=vl[i][0];
            if(cnt[lb]==useLimit) continue;
            cnt[lb]++;
            picked++;
            sum+=vl[i][1];
            if(picked==numWanted) break;
        }
        return sum;
    }
};