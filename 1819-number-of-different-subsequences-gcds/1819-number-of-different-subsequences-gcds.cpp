class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        vector<int> vis(mx+1,0);
        int ans=0;
        for(int x: nums){
            vis[x]=1;
        }
            for(int g=1;g<=mx;g++){
                int curr=0;
                for(int mul=g;mul<=mx;mul+=g){
                    if(vis[mul]){
                        curr=gcd(curr,mul);
                    }
                }
                if(curr==g) ans++;
            }
            
        
        return ans;
    }
};