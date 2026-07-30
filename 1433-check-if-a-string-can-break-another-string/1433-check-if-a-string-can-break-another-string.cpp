class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int n=s1.size();
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        bool valid=true;
        for(int i=0;i<n;i++){
            if(s1[i]<s2[i]){
                valid=false;
                break;
            }
        }
        if(valid) return true;
        valid=true;
        for(int i=0;i<n;i++){
            if(s1[i]>s2[i]){
                valid=false;
                break;
            }
        }
        return valid;
    }
};