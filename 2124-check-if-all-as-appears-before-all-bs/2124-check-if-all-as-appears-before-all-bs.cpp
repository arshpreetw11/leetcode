class Solution {
public:
    bool checkString(string s) {
        string sorted=s;
        sort(s.begin(),s.end());
        return s==sorted;
    }
};