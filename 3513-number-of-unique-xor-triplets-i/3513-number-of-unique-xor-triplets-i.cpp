class Solution {
public:
    int power(int a,int b){
        int val=1;
        while(b--){
            val*=a;
        }
        return val;
    }
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return n;
        }
        int msb=31 - __builtin_clz(n); 
        int highest=power(2,msb+1)-1;
        return highest+1;
    }
};