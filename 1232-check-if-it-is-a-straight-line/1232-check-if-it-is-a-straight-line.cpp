class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();
        sort(coordinates.begin(),coordinates.end());
        if(n==2) return true;
        int dy=coordinates[1][1]-coordinates[0][1];
        int dx=coordinates[1][0]-coordinates[0][0];
        for(int i=2;i<n;i++){
            int y=coordinates[i][1]-coordinates[0][1];
            int x=coordinates[i][0]-coordinates[0][0];
            if (1LL * x * dy != 1LL * y * dx) {
                return false;
            }
        }
        return true;
    }
};