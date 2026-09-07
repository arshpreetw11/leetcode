class Solution {
public:
    int LIS(vector<int>& points){
        int n=points.size();
        vector<int> v;
        for(int x: points){
            auto it=lower_bound(v.begin(),v.end(),x);
            if(it==v.end()){
                v.push_back(x);
            }else{
                *it=x;
            }
        }
        return v.size();
    }
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        int n=coordinates.size();
        //set<pair<int,int>> line;
        //line.insert({coordinates[k][0],coordinates[k][1]});
        int x=coordinates[k][0];
        int y=coordinates[k][1];
        sort(coordinates.begin(),coordinates.end(),[](vector<int>& a,vector<int>& b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        vector<int> left,right;
        for(auto &point:coordinates){
            int a=point[0];
            int b=point[1];

            if(a<x && b<y) {
                left.push_back(b);
            }
            if(a>x && b>y){
                right.push_back(b);
            }
        }

        return LIS(left)+1+LIS(right);
    }
};