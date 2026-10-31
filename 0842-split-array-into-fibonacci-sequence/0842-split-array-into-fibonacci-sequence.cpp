class Solution {
public:
    bool backtrack(string &s,int start,vector<int>&nums){
        if(start>=s.size() && nums.size()>=3) return true;
        int n=s.size();
        int mxSplit=(s[start]=='0')?1:10;
        for(int i=1;i<=mxSplit && start+i<=s.size();i++){
            long long num=stoll(s.substr(start,i));
            if(num>INT_MAX) return false;
            int sz=nums.size();
            if(sz>=2 && (long long)nums[sz-1]+nums[sz-2]<num) return false;
            if(sz<=1 || (long long)nums[sz-1]+nums[sz-2]==num) {
                nums.push_back(num);
                if(backtrack(s,start+i,nums)) return true;
                nums.pop_back();
            }
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string num) {
        vector<int> nums;
        backtrack(num,0,nums);
        return nums;
    }
};