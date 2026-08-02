class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>sorted=nums1;
        sort(sorted.begin(),sorted.end());
        int mod=1e9+7;
        long long total=0;
        int best=0;
        for(int i=0;i<n;i++){
            int curr=abs(nums1[i]-nums2[i]);
            total+=curr;
            auto it=lower_bound(sorted.begin(),sorted.end(),nums2[i]);
            
            if(it!=sorted.end()){
                best=max(best,curr-abs(*it-nums2[i]));
            }
            if(it!=sorted.begin()){
                --it;
                best=max(best,curr-abs(*it-nums2[i]));
            }
        }
        return (total-best)%mod;
        // vector<vector<int>> pairs;
        // int n=nums1.size();
        // for(int i=0;i<nums1.size();i++){
        //     int m=nums1[i];
        //     int n=nums2[i];
        //     //push_back in pairs; and sort;
        //     pairs.push_back({m,n});
        // }
        // int mn=*min_element(nums1.begin(),nums1.end());
        // int mx=*max_element(nums1.begin(),nums1.end());
        // //two replacement for each element in nums1;
        // int sum=0;
        // for(int i=0;i<n;i++){
        //     int x=abs(pairs[i][0]-pairs[i][1]);
        //     sum+=x;
        // }
        // if(sum==0) return 0;
        // int sum2=sum;
        // for(int i=0;i<n;i++){
        //     int curr=abs(pairs[i][0]-pairs[i][1]);
        //     int sum1=sum-curr;
        //     int x=min(abs(mn-pairs[i][1]),abs(mx-pairs[i][1]));
        //     sum2=min(sum2,sum1+x);
        // }
        // return min(sum,sum2);
    }
};