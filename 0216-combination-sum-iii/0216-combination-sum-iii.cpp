class Solution {
public:
vector<vector<int>> res;

void solve(vector<int>& temp,int idx,int k,int n){
    if(k==0 && n==0) {
        res.push_back(temp);
        return;
    }
    if(k<0 || n<0){
        return;
    }
    for(int i=idx;i<=9;i++){
        temp.push_back(i);
        solve(temp,i+1,k-1,n-i);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        
        solve(temp,1,k,n);
        return res;
    }
};