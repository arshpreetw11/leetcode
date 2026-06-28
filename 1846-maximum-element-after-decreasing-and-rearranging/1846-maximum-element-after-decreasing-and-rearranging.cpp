class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        int mx=0;
        int n=arr.size();
        int val=1;
        vector<int> temp(n);
        sort(arr.begin(),arr.end());
        if(arr[0]==1) {
            temp[0]=1;
            
        }
        else{
            arr[0]=1;
            val++;
        }
        for(int i=1;i<n;i++){
            arr[i]=min(arr[i],arr[i-1]+1);
        }
        return arr[n-1];
    }
};