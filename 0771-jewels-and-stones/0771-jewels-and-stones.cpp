class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,bool> mp;
        for(char j: jewels){
            mp[j]=true;
        }
        int cnt=0;
        for(char s:stones){
            if(mp[s]) cnt++;
        }
        return cnt;
    }
};