class Solution {
public:
    void merge(vector<pair<int,int>>& arr,int left,int mid,int right,vector<int>& ans){
        vector<pair<int,int>> temp;
        int i=left;
        int j=mid+1;
        int rightCount=0;

        while(i<=mid && j<=right){
            if(arr[j].first<arr[i].first){
                rightCount++;
                temp.push_back(arr[j++]);
            }
            else {
                ans[arr[i].second] += rightCount;
                temp.push_back(arr[i++]);
            }
        }
        while (i <= mid) {
            ans[arr[i].second] += rightCount;
            temp.push_back(arr[i++]);
        }
        while (j <= right) {
            temp.push_back(arr[j++]);
        }
        for (int k = left; k <= right; k++) {
            arr[k] = temp[k - left];
        }
    }
    void mergeSort(vector<pair<int,int>> & arr,int left,int right,vector<int>& ans){
        if(left>=right) return;
        int mid=left+(right-left)/2;
        mergeSort(arr,left,mid,ans);
        mergeSort(arr,mid+1,right,ans);

        merge(arr,left,mid,right,ans);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        vector<int> ans(n,0);
        mergeSort(arr,0,n-1,ans);
        return ans;
    }
};