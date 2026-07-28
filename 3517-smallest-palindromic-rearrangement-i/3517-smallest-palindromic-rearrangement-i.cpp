class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
        string res="";
        int mid=n/2;
        string temp(s.begin(),s.begin()+mid);
        sort(temp.begin(),temp.end());
        res+=temp;
        if(n%2){
            res+=s[mid];
        }
        reverse(temp.begin(),temp.end());
        res+=temp;
        return res;
        
    }
};