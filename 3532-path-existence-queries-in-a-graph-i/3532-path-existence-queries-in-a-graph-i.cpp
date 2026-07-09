class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> res(queries.size(),false);
        int prev=nums[0];
        nums[0]=0;

        for(int i=1;i<nums.size();i++){
            if(nums[i]-prev<=maxDiff){
                prev=nums[i];
                nums[i]=nums[i-1]+1;
            }
            else{
                prev=nums[i];
                nums[i]=0;
            }
        }

        for(int i=0;i<queries.size();i++){
            if(abs(queries[i][0]-queries[i][1])<=nums[max(queries[i][0],queries[i][1])]){
                res[i]=true;
            }
        }
        return res;
    }
};