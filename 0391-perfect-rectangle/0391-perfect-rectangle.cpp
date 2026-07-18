class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        vector<int>X,Y;
        for(auto &rec:rectangles){
            int x=rec[0],y=rec[1];
            X.push_back(x);
            Y.push_back(y);
        }
        int minX=*min_element(X.begin(),X.end());
        int minY=*min_element(Y.begin(),Y.end());
        int maxX=*max_element(X.begin(),X.end());
        int maxY=*max_element(Y.begin(),Y.end());

        long long total=0;
        set<pair<int, int>> corners;

        auto toggle = [&](pair<int, int> p) {
            if (corners.count(p))
                corners.erase(p);
            else
                corners.insert(p);
        };
        for (auto &r : rectangles) {
            int x1 = r[0], y1 = r[1];
            int x2 = r[2], y2 = r[3];

            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);

            total += 1LL * (x2 - x1) * (y2 - y1);

            toggle({x1, y1});
            toggle({x1, y2});
            toggle({x2, y1});
            toggle({x2, y2});
        }
        long long bigArea = 1LL * (maxX - minX) * (maxY - minY);

        if (total != bigArea)
            return false;

        if (corners.size() != 4)
            return false;

        if (!corners.count({minX, minY}))
            return false;
        if (!corners.count({minX, maxY}))
            return false;
        if (!corners.count({maxX, minY}))
            return false;
        if (!corners.count({maxX, maxY}))
            return false;

        return true;
    }
};