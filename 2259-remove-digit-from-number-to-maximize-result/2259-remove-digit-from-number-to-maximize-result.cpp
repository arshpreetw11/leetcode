class Solution {
public:
    string removeDigit(string number, char digit) {
        int n=number.size();
        string ans="";
        for(int i=0;i<n;i++){
            if(number[i]==digit){
                string left=number.substr(0,i);
                string right=number.substr(i+1);
                ans=max(ans,left+right);
            }
        }
        return ans;
    }
};