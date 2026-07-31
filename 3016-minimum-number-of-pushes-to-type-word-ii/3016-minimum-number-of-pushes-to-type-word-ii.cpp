class Solution {
public:
    int minimumPushes(string word) {
        int sz=word.size();
        unordered_map<char,int> freq;
        for(char ch : word){
            freq[ch]++;
        }
        sort(word.begin(),word.end(),[&](char a,char b){
            if(freq[a]==freq[b]) return a>b;
            return freq[a]>freq[b];
        });
        int inc=0,i=0,x=0,ans=0;
        while(i<word.size()){
            if(freq[word[i]]==0) {
                i++;
                continue;}
            if(x%8==0){
                inc++;
            }
            ans+=freq[word[i]]*inc;
            freq[word[i]]=0;
            x++;
            i++;
        }
        return ans;
    }
};