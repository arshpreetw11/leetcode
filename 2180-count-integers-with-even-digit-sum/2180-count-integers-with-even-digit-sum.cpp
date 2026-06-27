class Solution {
public:
    bool evenSum(int n){
        int sum=0;
        while(n!=0){
            sum+=n%10;
            n/=10;
        }
        if(sum%2==0) return true;
        return false;
    }
    int countEven(int num) {

        int temp=num,sum=0;
        while(num!=0){
            sum+=num%10;
            num/=10;
        }
        return sum%2==0 ? temp/2 : (temp-1)/2 ;

        //Solution 2:
        // vector<int> dp(num+1,0);

        // for(int i=2;i<=num;i++){
        //     if(evenSum(i)){
        //         dp[i]=dp[i-1]+1;
        //     }
        //     else{
        //         dp[i]=dp[i-1];
        //     }
        // }
        // return dp[num];
    }
};