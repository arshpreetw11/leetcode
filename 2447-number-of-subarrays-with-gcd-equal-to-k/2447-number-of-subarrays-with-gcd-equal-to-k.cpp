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
            vector<int> temp;
            for(int j=i;j<n;j++){
                temp.push_back(nums[j]);
                int val=gcd_vec(temp);
                if(val==k) ans++;
                else if(val<k) break;
            }
        }
        return ans;
    }
};