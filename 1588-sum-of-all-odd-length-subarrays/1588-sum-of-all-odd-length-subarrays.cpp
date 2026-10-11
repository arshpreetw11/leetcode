class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int num=0;
            int val=0;
            for(int j=i;j<n;j++){
                num++;
                val+=arr[j];
                if(num%2){
                    sum+=val;
                }
            }
        }
        return sum;
    }
};