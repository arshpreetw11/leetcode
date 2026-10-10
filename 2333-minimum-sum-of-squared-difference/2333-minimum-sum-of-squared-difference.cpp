class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k=(long long)k1+k2;
        vector<long long> freq(100001,0);
        for(int i=0;i<nums1.size();i++){
            long long d=abs((long long) nums1[i]-nums2[i]);
            freq[d]++;
        }
        for(int d=100000;d>0;d--){
            if(freq[d]==0) continue;
            long long take=min(freq[d],k);
            freq[d]-=take;
            freq[d-1]+=take;

            k-=take;
        }
        long long ans=0;
        for(int d=1;d<100001;d++){
            ans+=freq[d]*d*d;
        }
        return ans;
    }
};