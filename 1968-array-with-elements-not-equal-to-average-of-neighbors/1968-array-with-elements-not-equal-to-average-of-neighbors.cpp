class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        bool ok=true;
        int n=nums.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            if(i>0 && i+1<n){
                double avg=(nums[i-1]+nums[i+1])/2;
                if(avg==nums[i]){
                    ok=false;
                    break;
                }
            }
        }
        if(ok) return nums;
        sort(nums.begin(),nums.end());
        int i=0,j=n-1;
        while(i<j){
            int x=nums[i];
            int y=nums[j];
            res.push_back(x);
            res.push_back(y);
            i++;
            j--;
        }
        if(res.size()!=n)res.push_back(nums[i]);
        return res;
    }
};