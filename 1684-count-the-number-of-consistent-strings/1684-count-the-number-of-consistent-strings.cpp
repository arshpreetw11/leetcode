class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>temp(allowed.begin(),allowed.end());
        int cnt=0;
        for(string str: words){
            bool exist=true;
            for(char ch : str){
                if(!temp.count(ch)){
                    exist=false;
                    break;
                }
            }
            if(exist) cnt++;
        }
        return cnt;
    }
};