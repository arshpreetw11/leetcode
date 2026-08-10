class Solution {
public:
    bool solve(string& s,int k){
        int n=s.size();
        vector<int> base(26,0);
        for(int i=0;i<k;i++){
            base[s[i]-'a']++;
        }
        for(int i=k;i<n;i+=k){
            vector<int> freq(26,0);
            for(int j=i;j<i+k;j++){
                freq[s[j]-'a']++;
            }
            if(freq!=base) return false;
        }
        return true;
    }
    int minAnagramLength(string s) {
        int n=s.size(),distinct=0;
        for(int k=1;k<=n;k++){
            if(n%k==0 && solve(s,k)){
                return k;
            }
        }
        return -1;
    }
};