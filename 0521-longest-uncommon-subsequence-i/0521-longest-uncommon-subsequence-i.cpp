class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a==b) return -1;
        int mx=max(a.size(),b.size());
        return mx;
    }
};