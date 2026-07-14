class Solution {
public:
    int GCD(int mn,int mx){
        if(mn==mx) return mn;
        for(int i=mn;i>=1;i--){
            if(mn%i==0 && mx%i==0) return i;
        }
        return 1;
    }
    int findGCD(vector<int>& nums) {
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        return GCD(mn,mx);
    }
};