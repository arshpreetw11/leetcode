class Solution {
public:
    
    int minimumOperations(string num) {
        int n=num.size();
        int ans=INT_MAX,zero=-1,five=-1;
        for(int i=n-1;i>=0;i--){
            if(num[i]=='0'){
                zero=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(num[i]=='5'){
                five=i;
                break;
            }
        }
        int ans0=INT_MAX,ans5=INT_MAX;
        int cntzero=-1,cntfive=-1;
        if(zero!=-1) ans=min(ans,n-1);
        if(zero!=-1){
            for(int i=zero-1;i>=0;i--){
                if(num[i]=='5' || num[i]=='0'){
                    cntzero=zero-i-1;
                    break;
                }
            }
            if(cntzero!=-1){
                ans0=cntzero+n-1-zero;
            }
        }
        if(five!=-1){
            for(int i=five-1;i>=0;i--){
                if(num[i]=='2' || num[i]=='7'){
                    cntfive=five-i-1;
                    break;
                }
            }
            if(cntfive!=-1){
                ans5=cntfive+n-1-five;
            }
        }
        ans = min(ans, min(ans0, ans5));
        return ans==INT_MAX?n:ans;
    }
};