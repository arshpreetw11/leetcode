class Solution {
public:
    long long mergeSort(vector<long long>& prefix,int left,int right,int lower,int upper){
        if(left>=right){
            return 0;
        }
        int mid=left+(right-left)/2;
        long long cnt=0;
        cnt+=mergeSort(prefix,left,mid,lower,upper);
        cnt+=mergeSort(prefix,mid+1,right,lower,upper);
        int l=mid+1;
        int r=mid+1;

        for (int i = left; i <= mid; i++) {
            while (l <= right && prefix[l] - prefix[i] < lower)
                l++;

            while (r <= right && prefix[r] - prefix[i] <= upper)
                r++;

            cnt += (r - l);
        }

        vector<long long> temp;
        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right) {
            if (prefix[i] <= prefix[j])
                temp.push_back(prefix[i++]);
            else
                temp.push_back(prefix[j++]);
        }

        while (i <= mid)
            temp.push_back(prefix[i++]);

        while (j <= right)
            temp.push_back(prefix[j++]);

        for (int k = left; k <= right; k++)
            prefix[k] = temp[k - left];
        return cnt;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        vector<long long> prefix(n+1,0);
        int sum=0;
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        return mergeSort(prefix,0,n,lower,upper);
    }
};