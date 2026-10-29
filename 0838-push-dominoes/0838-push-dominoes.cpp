class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        vector<int> forces(n,0);
        int f=0;
        for(int i=0;i<n;i++){
            if(dominoes[i]=='R'){
                f=n;
            }else if(dominoes[i]=='L'){
                f=0;
            }else{
                f=max(0,f-1);
            }
            forces[i]+=f;
        }
        f=0;
        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='L'){
                f=n;
            }else if(dominoes[i]=='R'){
                f=0;
            }else{
                f=max(0,f-1);
            }
            forces[i]-=f;
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(forces[i]>0) ans+='R';
            else if(forces[i]<0) ans+='L';
            else ans+='.';
        }
        return ans;
    }
};