class Solution {
public:
    int gcd_vec(vector<int> num){
        int x=num[0];
        for(int i=1;i<num.size();i++){
            x=gcd(x,num[i]);
        }
        return x;
    }
    int subarrayGCD(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int g=0;
            for(int j=i;j<n;j++){
                g=gcd(g,nums[j]);
                if(g==k) ans++;
                else if(g<k) break;
            }
        }
        return ans;
    }
};