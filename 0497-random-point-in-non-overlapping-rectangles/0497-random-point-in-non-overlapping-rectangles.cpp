class Solution {
public:
    vector<int> v;
    vector<vector<int>> rects;
    int area(vector<int>& r){
        return (r[2]-r[0]+1 )* (r[3]-r[1]+1);
    }
    Solution(vector<vector<int>>& _) {
        rects=_;
        for(auto& r: rects){
            v.push_back(area(r)+(v.empty()?0:v.back()));
        }
    }
    
    vector<int> pick() {
        int rd=rand()%v.back();
        auto it=upper_bound(v.begin(),v.end(),rd);
        int idx=it-v.begin();
        auto r=rects[idx];
        return{
            rand()%(r[2]-r[0]+1)+r[0],
            rand()%(r[3]-r[1]+1)+r[1],
        };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */