class Solution {
public:
    bool check(vector<int>& freq,int &j,int &k){
        int ct=0;
        for(int i=0;i<freq.size();i++){
            if(freq[i]==0) continue;
            if(freq[i]!=k) return false;
            else ct++;
        }
        if(ct>j) return false;
        return true;
    }
    long long int fun(string & s,int & k){
        long long int cnt=0;
        int n=s.length();
        for(int j=1;j<=26;j++){
            int len=k*j;
            vector<int> freq(26,0);
            if(len>n)break;
            for(int i=0;i<len;i++){
                freq[s[i]-'a']++;
            }
            if(check(freq,j,k)) cnt++;
            for(int i=len;i<n;i++){
                char prev=s[i-len];
                char next=s[i];
                freq[prev-'a']--;
                freq[next-'a']++;
                if(check(freq,j,k)) cnt++;
            }
        }
        return cnt;
    }
    int countCompleteSubstrings(string word, int k) {
        long long int ans=0;
        string res="";
        int n=word.size();
        for(int i=0;i<n;i++){
            res+=word[i];
            if(i<=n-2){
                if(abs(word[i]-word[i+1])>2){
                    ans+=fun(res,k);
                    res="";
                }
            }
        }
        ans+=fun(res,k);
        return ans;
    }
};