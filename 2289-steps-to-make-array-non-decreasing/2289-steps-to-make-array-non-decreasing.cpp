class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int steps=0;
        int ans=0;
        stack<pair<int,int>> st; // {value,steps};
        for(int x: nums){
            int cur=0;
            while(!st.empty() && st.top().first<=x){
                cur=max(cur,st.top().second);
                st.pop();
            }
            if(!st.empty()){
                cur++;
            }
            ans=max(ans,cur);
            st.push({x,cur});
        }
        return ans;

        // while(true){
        //     vector<int> temp=nums;
        //     sort(temp.begin(),temp.end());
        //     if(temp==nums) return steps;
        //     temp={};
        //     for(int i=1;i<nums.size();i++){
        //         if(nums[i-1]>nums[i]){
        //             continue;
        //         }
        //         temp.push_back(nums[i-1]);
        //     }
        //     temp.push_back(nums[nums.size()-1]);
        //     nums=temp;
        //     steps++;
        // }
        
        // return steps;
    }
};