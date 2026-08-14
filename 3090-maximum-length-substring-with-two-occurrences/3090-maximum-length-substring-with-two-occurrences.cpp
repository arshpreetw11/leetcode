class Solution {
public:
    int maximumLengthSubstring(string s) {
        int mx_len=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            unordered_map<char,int> freq;
            int j;
            for(j=i;j<n;j++){
                freq[s[j]]++;
                if(freq[s[j]]>2){
                    mx_len=max(mx_len,j-i);
                    break;
                }
            }
            mx_len=max(mx_len,j-i);
        }
        return mx_len;
    }
};