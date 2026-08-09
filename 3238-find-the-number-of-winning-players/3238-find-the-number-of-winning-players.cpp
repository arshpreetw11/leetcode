class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int,vector<int>> mp;
        for(auto &p:pick){
            mp[p[0]].push_back(p[1]);
        }
        int win=0;
        for(auto &m:mp){
            int player = m.first;
            unordered_map<int, int> freq;
            for (int color : m.second) {
                freq[color]++;
            }
            bool ok = false;
            for (auto &[color, cnt] : freq) {
                if (cnt >= player + 1) {
                    ok = true;
                    break;
                }
            }

            if (ok)
                win++;
        }
        return win;
    }
};