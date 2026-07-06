class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> arr;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int val=matrix[i][j];
                arr.push_back(val);
            }
        }sort(arr.begin(),arr.end());
        return arr[k-1];
    }
};