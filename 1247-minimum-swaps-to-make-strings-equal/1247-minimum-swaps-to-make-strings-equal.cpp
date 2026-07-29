class Solution {
public:
    void check(string& s1,string& s2,int i,int n){
        int j=n-1;
        while(s2[j]==s1[i]) j--;
        swap(s2[j],s1[i]);
    }
    int minimumSwap(string s1, string s2) {
        int n=s1.size();
        int xy=0;
        int yx=0;
        for(int i=0;i<n;i++){
            if(s1[i]=='x' && s2[i]=='y') xy++;
            else if(s1[i]=='y' && s2[i]=='x') yx++;
        }
        if((xy+yx)%2) return -1;
        return xy/2 + yx/2 +2 *(xy%2);
    }
};