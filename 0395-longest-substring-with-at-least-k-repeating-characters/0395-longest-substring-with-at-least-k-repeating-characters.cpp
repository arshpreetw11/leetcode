class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        int len=0;
        for(int i=0;i<n;i++){
            string sub="";
            unordered_map<char,int> freq;
            for(int j=i;j<n;j++){
                sub+=s[j];
                freq[s[j]]++;
                bool is=true;
                for(auto &[ch,num]: freq){
                    if(num<k){
                        is=false;
                        break;
                    }
                }
                if(is) len=max(len,j-i+1);
            }
        }
        return len;
    }
};