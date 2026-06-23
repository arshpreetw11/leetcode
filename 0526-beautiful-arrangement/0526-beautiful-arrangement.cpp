class Solution {
public:
    int countArrangement(int n) {
        vector<vector<int>> ans;
        vector<int> arr;
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }
        solve(ans,arr,0);
        return ans.size();
    }
    void solve(vector<vector<int>>& ans,vector<int>& arr,int i){
        if(i==arr.size()){
            ans.push_back(arr);
            return;
        }
        for(int j=i;j<arr.size();j++){
            swap(arr[j],arr[i]);
            if((arr[i]%(i+1))!=0 && ((i+1)%arr[i]) != 0) {
                swap(arr[j],arr[i]);
                continue;}
            solve(ans,arr,i+1);
            swap(arr[j],arr[i]);
        }
    }
};