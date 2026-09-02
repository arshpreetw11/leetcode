class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;

        int mid=1<<(n-2);
        if(k<=mid) return kthGrammar(n-1,k);
         return 1-kthGrammar(n-1,k-mid);
        // string current="0";
        // while(--n){
        //     string next="";
        //     for(char c:current){
        //         if(c=='0'){
        //             next+="01";
        //         }
        //         else{
        //             next+="10";
        //         }
        //     }
        //     current=next;
        // }
        // int x=current[k-1]-'0';
        // return x;
    }
};