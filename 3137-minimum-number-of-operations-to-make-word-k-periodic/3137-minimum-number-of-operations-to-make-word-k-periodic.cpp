class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        //substring of length k;
        int mx=0;
        unordered_map<string,int> freq;
        for(int i=0;i<word.size();i+=k){
            string sub=word.substr(i,k);
            freq[sub]++;
            mx=max(mx,freq[sub]);
        }
        int len=word.size()/k;
        return len-mx;
    }
};