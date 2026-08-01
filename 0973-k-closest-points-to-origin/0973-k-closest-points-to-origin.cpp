class Solution {
public:
    int distance(int x,int y){
        int d=x*x+y*y;
        return d;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(),points.end(),[&](vector<int>&a,vector<int>&b){
            return distance(a[0],a[1])<distance(b[0],b[1]);
        });
        vector<vector<int>> res;
        int i=0;
        while(k-- && i<points.size()){
            
            res.push_back(points[i]);
            i++;
        }
        return res;
    }
};