class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(),zero=0;
        for(int x:nums){
            if(x==0) zero++;
        }
        if(zero==n) return queries.size();

        sort(queries.begin(),queries.end());
        vector<int> diff(n+1,0);
        priority_queue<int> q;
        int active=0;
        int used=0;
        int j=0;
        int sz=queries.size();
        for(int i=0;i<n;i++){
            active+=diff[i];
            while(j<sz && queries[j][0]<=i){
                q.push(queries[j][1]);
                j++;
            }

            while(active<nums[i]){
                if(q.empty()||q.top()<i) return -1;
                int r=q.top();
                q.pop();

                active++;
                used++;

                if(r+1<diff.size()){
                    diff[r+1]--;
                }

            }
            while(!q.empty() && q.top()<i)
                q.pop();
        }
        return sz-used;
    }
};