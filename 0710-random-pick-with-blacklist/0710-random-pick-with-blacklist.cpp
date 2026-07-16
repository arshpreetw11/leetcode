class Solution {
public:
    int m;
    unordered_map<int,int> mp;

    Solution(int n, vector<int>& blacklist) {
        m = n - blacklist.size();
        unordered_set<int> black(blacklist.begin(), blacklist.end());
        int last = n - 1;
        for (int b : blacklist) {
            if (b < m) {
                while (black.count(last))
                    last--;
                mp[b] = last;
                last--;
            }
        }
    }
    
    int pick() {
        int x=rand()%m;
        if(mp.count(x)){
            return mp[x];
        }
        return x;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */