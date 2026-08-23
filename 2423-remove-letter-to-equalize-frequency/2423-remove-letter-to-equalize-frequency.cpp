class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> freq(26,0);
        for(char ch:word){
            freq[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            freq[i]--;
            int target=0;
            bool ok=true;
            for(int j=0;j<26;j++){
                if(freq[j]==0) continue;
                if(target==0){
                    target=freq[j];
                }else if(target!=freq[j]){
                    ok=false;
                    break;
                }
            }
            if(ok) return true;
            freq[i]++;
        }
        return false;
    }
};