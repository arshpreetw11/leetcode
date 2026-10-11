class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),[&](string a,string b){
            if(a.size()==b.size()){
                for(int i=0;i<a.size();i++){
                    if(a[i]>b[i]) return a>b;
                }
                return a>b;
            }
            return a.size()>b.size();
        });
        return nums[k-1];
    }
};