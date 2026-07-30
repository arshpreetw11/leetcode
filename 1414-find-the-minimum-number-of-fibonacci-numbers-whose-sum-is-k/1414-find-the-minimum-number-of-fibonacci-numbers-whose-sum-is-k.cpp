class Solution {
public:
    vector<int> fibo;

    int findMinFibonacciNumbers(int k) {
        fibo.push_back(1);
        fibo.push_back(1);
        int i=2,val=1;
        while(val<=k){
            int x=fibo[i-1]+fibo[i-2];
            fibo.push_back(x);
            val=x;
            i++;
        }
        int ans=0;
        for(int i=fibo.size()-1;i>=0;i--){
            if(fibo[i]<=k){
                k-=fibo[i];
                ans++;
            }
        }
        return ans;
    }
};