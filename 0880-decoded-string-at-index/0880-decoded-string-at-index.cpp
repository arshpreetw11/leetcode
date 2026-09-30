class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size=0;
        for(char c:s){
            if(isdigit(c))
                size*=(c-'0');
            else 
                size++;
        }
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            char c=s[i];
            if(isdigit(c)){
                int d=c-'0';
                size/=d;
                k%=size;
            }else{
                if(k==0 || k==size){
                    return string(1,c);
                }
                size--;
            }
        }
        return "";
    }
};