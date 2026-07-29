class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        int i=0;
        int n=s.size();
        while(i<n){
            if(s[i]!='9'){
                s[i]='9';
                break;
            }
            i++;
        }
        return stoi(s);
    }
};