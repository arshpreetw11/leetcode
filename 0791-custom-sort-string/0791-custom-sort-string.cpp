class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> pos;
        int i=1;
        for(char ch: order){
            pos[ch]=i;
            i++;
        }
        sort(s.begin(),s.end(),[&](char a, char b){
            return pos[a]<pos[b];
        });
        return s;
    }
};