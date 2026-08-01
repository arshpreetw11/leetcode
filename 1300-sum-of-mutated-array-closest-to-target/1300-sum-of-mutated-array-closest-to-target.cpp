class Solution {
public:
    int getSum(vector<int>& arr,int value){
        int sum=0;
        for(int x:arr){
            sum+=min(x,value);
        }
        return sum;
    }
    int findBestValue(vector<int>& arr, int target) {
        int low=0;
        int high=*max_element(arr.begin(),arr.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(getSum(arr,mid)<target)
                low=mid+1;
            else
                high=mid-1;
        }
        int sum1=getSum(arr,low);
        int sum2=getSum(arr,low-1);
        if(abs(sum2-target)<=abs(sum1-target))
            return low-1;
        return low;
    }
};