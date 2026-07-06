class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int m=nums1.size();
        int n=nums2.size();
        if(nums1.empty() || nums2.empty()) return ans;
        priority_queue<tuple<int,int,int>,
                       vector<tuple<int,int,int>>,
                       greater<tuple<int,int,int>>> pq;
        for(int i=0;i<min(m,k);i++)
            pq.push({nums1[i] + nums2[0], i, 0});

        while(k-- && !pq.empty()){
            auto [sum,i,j]=pq.top();
            pq.pop();
            ans.push_back({nums1[i],nums2[j]});
            if(j+1<n){
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }

        return ans;
    }
};