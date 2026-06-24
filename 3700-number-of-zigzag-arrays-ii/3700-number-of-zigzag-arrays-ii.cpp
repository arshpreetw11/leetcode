class Solution {
public:
    static const int mod = 1e9 + 7;
    vector<long long> multiplyMatVec(vector<vector<long long>> &A, vector<long long> &v){
        int sz=A.size();
        vector<long long> res(sz,0);
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                res[i] = (res[i] + A[i][j] * v[j]) % mod;
            }
        }
        return res;
    }
    vector<vector<long long>> power(vector<vector<long long>>& base,long long exp){
        int sz=base.size();
        vector<vector<long long>> res(sz,vector<long long>(sz,0));
        for (int i = 0; i < sz; i++)
            res[i][i] = 1;

        while (exp) {
            if (exp & 1)
                res = multiply(res, base);

            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }
    vector<vector<long long>> multiply(vector<vector<long long>>& A,vector<vector<long long>>& B){
        int sz=A.size();
        vector<vector<long long>> C(sz,vector<long long>(sz,0));
        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < sz; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
                }
            }
        }return C;
    }

    int zigZagArrays(int n, int l, int r) {
        int m=r-l+1;
        int len=2*m;
        vector<vector<long long >> mat(len,vector<long long>(len,0));
        if(n==1) return m;

        for(int x=0;x<m;x++){
            for(int y=x+1;y<m;y++){
                mat[y][x+m]=1;
            }
            for(int y=0;y<x;y++){
                mat[m+y][x]=1;
            }
        }
        vector<vector<long long>> P = power(mat, n - 1);
        vector<long long> startUp(len, 0), startDown(len, 0);

        for (int i = 0; i < m; i++) {
            startDown[i] = 1;
            startUp[m + i] = 1;
        }

        vector<long long> endUp = multiplyMatVec(P, startUp);
        vector<long long> endDown = multiplyMatVec(P, startDown);
        
        long long ans=0;
        for(auto & x: endUp){
            ans=(ans+x)%mod;
        }
        for(auto & x: endDown){
            ans=(ans+x)%mod;
        }
        return ans%mod;
    }
};