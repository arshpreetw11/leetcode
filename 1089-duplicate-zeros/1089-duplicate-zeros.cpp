class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> ans;
        for(int n:arr){
            if(n==0) ans.push_back(0);
            ans.push_back(n);
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=ans[i];
        }
    }
};