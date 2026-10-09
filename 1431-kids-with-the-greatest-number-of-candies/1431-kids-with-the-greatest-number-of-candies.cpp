class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx=*max_element(candies.begin(),candies.end());
        int n=candies.size();
        vector<bool> res;
        for(int c:candies){
            int total=c+extraCandies;
            if(total>=mx) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};