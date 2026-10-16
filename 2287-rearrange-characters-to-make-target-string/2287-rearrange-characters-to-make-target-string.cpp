class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> findT(26,0),findS(26,0);
        for(char c:target){
            findT[c-'a']++;
        }
        for(char c:s){
            findS[c-'a']++;
        }
        int ans=INT_MAX;
        for(int i=0;i<26;i++){
            if(findT[i]>0){
                ans=min(ans,findS[i]/findT[i]);
            }
        }
        return ans;
    }
};