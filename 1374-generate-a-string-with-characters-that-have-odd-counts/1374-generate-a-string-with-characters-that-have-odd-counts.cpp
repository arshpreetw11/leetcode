class Solution {
public:
    string generateTheString(int n) {
        char c='a';
        string s="";
        if(n%2==0){
            for(int i=0;i<n-1;i++){
                s.push_back(c);
            }
            c='b';
            s.push_back(c);
        }else{
            for(int i=0;i<n;i++){
                s.push_back(c);
            }
        }
        return s;
    }
};