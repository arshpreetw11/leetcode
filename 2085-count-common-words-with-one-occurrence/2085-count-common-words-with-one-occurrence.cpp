class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> freq1,freq2;
        for(string s:words1){
            freq1[s]++;
        }
        for(string s:words2){
            freq2[s]++;
        }
        int cnt=0;
        for(auto &[s,f]:freq1){
            if(f==1 && freq2[s]==1) cnt++;
        }
        return cnt;
    }
};