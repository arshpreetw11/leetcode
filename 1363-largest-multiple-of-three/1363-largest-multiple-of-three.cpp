class Solution {
public:
bool removeOne(vector<int>& digits, int rem) {
    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] % 3 == rem) {
            digits.erase(digits.begin() + i);
            return true;
        }
    }
    return false;
}
bool removeTwo(vector<int>& digits, int rem) {
    vector<int> idx;

    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] % 3 == rem) {
            idx.push_back(i);
            if (idx.size() == 2) break;
        }
    }

    if (idx.size() != 2)
        return false;

    digits.erase(digits.begin() + idx[0]);
    digits.erase(digits.begin() + idx[1]);

    return true;
}
    string largestMultipleOfThree(vector<int>& digits) {
        //sum of the digits is multiple of 3;
        string s="";
        sort(digits.begin(),digits.end(),greater<int>());
        int sum=0;
        for(int n:digits){
            sum+=n;
            s+=n+'0';
        }
        if(sum%3==0){
            if(s[0]=='0') return "0";
            return s;
        }
        if(sum%3==1){
            if(!removeOne(digits,1)){
                if(!removeTwo(digits,2)){
                    return "";
                }
            }
        }
        else{
            if(!removeOne(digits,2)){
                if(!removeTwo(digits,1)){
                    return "";
                }
            }
        }
        if(digits.empty()){
            return "";
        }
        if(digits[0]==0) return "0";
        string ans="";
        for(int x: digits){
            ans+=char(x+'0');
        }
        return ans;
    }
};