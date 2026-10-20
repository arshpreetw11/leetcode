class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> XOR(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int up=(i>0)?XOR[i-1][j]:0;
                int left=(j>0)?XOR[i][j-1]:0;
                int dig=(i>0 && j>0)?XOR[i-1][j-1]:0;
                XOR[i][j]=matrix[i][j]^up^left^dig;
            }
        }
        vector<int> arr;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                arr.push_back(XOR[i][j]);
            }
        }
        sort(arr.begin(),arr.end(),greater<int>());
        return arr[k-1];
    }
};