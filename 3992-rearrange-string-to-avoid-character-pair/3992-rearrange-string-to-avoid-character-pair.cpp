class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        if(x<y)
        sort(s.begin(),s.end(),greater<int>());
        else 
        sort(s.begin(),s.end());
        return s;
    }
};