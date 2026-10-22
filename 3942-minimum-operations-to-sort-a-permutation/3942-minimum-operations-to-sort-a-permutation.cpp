class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n=nums.size();
        int pos=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                pos=i;
                break;
            }
        }
        int ans=INT_MAX;
        auto check=[&](int step){
            for(int i=1;i<n;i++){
                int prev=(pos+(i-1)*step)%n;
                if(prev<0) prev+=n;
                int curr=(pos+i*step)%n;
                if(curr<0) curr+=n;

                if(nums[prev]>nums[curr]) return false;
            }
            return true;
        };

        if(check(1)){
            ans=min(ans,pos);
            ans=min(ans,n-pos+2);
        }
        if(check(-1)){
            ans=min(ans,pos+2);
            ans=min(ans,n-pos);
        }

        return ans==INT_MAX?-1:ans;
        // vector<int> target=nums;
        // sort(target.begin(),target.end());
        // if(nums==target) return 0;
        // int mn=INT_MAX;
        
        // int n=nums.size();
        // for(int k=1;k<=n;k++){
        //     vector<int> cur;
        //     for(int i=0;i<n;i++){
        //         cur.push_back(nums[(i+k)%n]);
        //     }
        //     if(cur==target) {
        //         mn=min(mn,k);
        //     }
        // }
        // vector<int> rev=nums;
        // reverse(rev.begin(),rev.end());
        
        // for(int k=0;k<n;k++){
        //     vector<int> cur;
        //     for (int i = 0; i < n; i++) {
        //         cur.push_back(rev[(i + k) % n]);
        //     }
        //     if(cur==target) {
        //         mn=min(mn,k+1);
        //     }
        // }
        // return mn==INT_MAX?-1:mn;
        // queue<vector<int>> q;
        // set<vector<int>> visited;

        // q.push(nums);
        // visited.insert(nums);
        
        // int op=0;
        // while(!q.empty()){
        //     int sz=q.size();
        //     while(sz--){
        //         vector<int> cur=q.front();
        //         q.pop();
        //         vector<int> reversed=cur;
        //         reverse(reversed.begin(),reversed.end());
        //         if(reversed==target) return op+1;

        //         if(visited.find(reversed)==visited.end()){
        //             visited.insert(reversed);
        //             q.push(reversed);
        //         }
        //         vector<int> rotated=cur;
        //         int first=rotated[0];
        //         rotated.erase(rotated.begin());
        //         rotated.push_back(first);

        //         if(rotated==target) return op+1;

        //         if(visited.find(rotated)==visited.end()){
        //             visited.insert(rotated);
        //             q.push(rotated);
        //         }
        //     }
        //     op++;
        // }
        // return -1;
    }
};