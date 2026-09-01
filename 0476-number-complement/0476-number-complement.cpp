class Solution {
public:
string binary(int n){
    string sub="";
    while(n!=0){
        if(n%2) sub.push_back('1');
        else sub.push_back('0');
        n/=2;
    }
    reverse(sub.begin(),sub.end());
    return sub;
}
string comp(string num){
    for(int i=0;i<num.size();i++){
        if(num[i]=='1') num[i]='0';
        else num[i]='1';
    }
    return num;
}
int number(string s){
    int res=0;
    for(char c:s){
        res=res*2+(c-'0');
    }
    return res;
}
    int findComplement(int num) {
        string b=binary(num);
        b=comp(b);
        return number(b);
    }
};