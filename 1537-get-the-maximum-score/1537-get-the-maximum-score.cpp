class Solution {
public:
    int mod=1e9+7;
    
    int n1,n2;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        n1=nums1.size(),n2=nums2.size();

        int i=0,j=0;
        long long sum1=0,sum2=0;
        long long ans=0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                sum1+=nums1[i];
                i++;
            }else if(nums1[i]>nums2[j]){
                sum2+=nums2[j];
                j++;
            }else{
                ans+=max(sum1,sum2);
                ans+=nums1[i];
                sum1=0;
                sum2=0;
                i++;
                j++;
            }
        }
        while(i<n1){
            sum1+=nums1[i++];
        }
        while(j<n2){
            sum2+=nums2[j++];
        }
        ans+=max(sum1,sum2);
        return ans%mod;
    }
};