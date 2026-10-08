class Solution {
public:
int mx=0;
    void check(int i,vector<string>& words, vector<char>& letters, vector<int>& score,vector<int>& freq,int ans){
        int s=0;
        if(i==words.size()){
            mx=max(mx,ans);
            return ;
        }
        vector<int> f=freq;
        for(char c:words[i]){
            if(f[c-'a']==0) {
                check(i+1,words,letters,score,freq,ans);
                return;
            }
            else{
                s+=score[c-'a'];
                f[c-'a']--;
            }
        }

        check(i+1,words,letters,score,f,ans+s);
        check(i+1,words,letters,score,freq,ans);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26,0);
        for(char c:letters){
            freq[c-'a']++;
        }   
        check(0,words,letters,score,freq,0);
        return mx;
    }
};