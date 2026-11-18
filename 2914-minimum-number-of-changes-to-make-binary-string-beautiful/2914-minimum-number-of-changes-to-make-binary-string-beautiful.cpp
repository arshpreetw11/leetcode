class Solution {
public:
    int minChanges(string s) {
        int n=s.size();
        int diff=0;
        for(int i=0;i<n;i+=2){
            char c1=s[i],c2=s[i+1];
            if(c1!=c2) diff++;
        }
        return diff;
    }
};