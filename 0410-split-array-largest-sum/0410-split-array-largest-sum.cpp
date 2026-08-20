class Solution {
public:
    bool check(vector<int>& nums,int cut,long long mx){
        int acc=0;
        for(int num:nums){
            if(num>mx){
                return false;
            }
            else if(acc+num<=mx) acc+=num;
            else{
                --cut;
                acc=num;
                if(cut<0) return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        long long left=0,right=0;
        for(int num:nums){
            left=max(left,(long long)num);
            right+=num;
        }
        while(left<right){
            long long mid=left+(right-left)/2;
            if(check(nums,k-1,mid)) right=mid;
            else left=mid+1;
        }
        return left;
    }
};