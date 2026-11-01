class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int left=1,right=k+1;
        for(int i=0;i<=k;i++){
            if(i%2==0) ans.push_back(left++);
            else ans.push_back(right--);
        }
        for(int i=k+2;i<=n;i++){
            ans.push_back(i);
        }
        return ans;
    }
};