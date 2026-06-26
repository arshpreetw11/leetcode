class Solution {
public:
    string getHint(string secret, string guess) {
        int cows=0;
        int bulls=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                bulls++;
                secret[i]=guess[i]=-1;
            } 
        }
        unordered_map<int,int> freq;
        for(int n: secret){
            if(n!=-1) freq[n]++;
        }
        for(int n: guess){
            if(freq[n]!=0){
                cows++;
                freq[n]--;
            }
        }
        string res=to_string(bulls)+"A"+to_string(cows)+"B";
        return res;
    }
};