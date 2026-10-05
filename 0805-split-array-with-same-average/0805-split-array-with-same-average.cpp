class Solution {
public:

    void generate(vector<int>& nums,int idx,int end,int cnt,long long sum,vector<vector<int>>& sums){
        if(idx==end){
            sums[cnt].push_back(sum);
            return;
        }
        generate(nums,idx+1,end,cnt,sum,sums);
        generate(nums,idx+1,end,cnt+1,sum+nums[idx],sums);
    }
    bool splitArraySameAverage(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int x:nums){
            sum+=x;
        }
        bool possible=false;
        for(int k=1;k<=n/2;k++){
            if((k*sum)%n==0) {
                possible=true;
                break;
            }
        }
        if(!possible)
            return false;
            int mid=n/2;
        vector<vector<int>> left(mid + 1);
        vector<vector<int>> right(n - mid + 1);
        
        generate(nums,0,mid,0,0,left);
        generate(nums,mid,n,0,0,right);

        for(auto &v: right){
            sort(v.begin(),v.end());
        }
        for(int k = 1; k <= n/2; k++) {

            if((k * sum) % n != 0)
                continue;

            int target = (k * sum) / n;

            for(int a = 0; a <= k; a++) {

                int b = k - a;

                if(a > mid || b > n - mid)
                    continue;

                for(int x : left[a]) {

                    int needed = target - x;

                    if(binary_search(right[b].begin(),
                                    right[b].end(),
                                    needed)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};