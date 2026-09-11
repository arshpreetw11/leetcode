class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mod=1e9+7;
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        long long mxH=horizontalCuts[0]-0;
        for(int i=1;i<horizontalCuts.size();i++){
            long long x=horizontalCuts[i];
            long long y=horizontalCuts[i-1];
            mxH=max(mxH,x-y);
        }
        mxH=max(mxH,(long long)h-horizontalCuts.back());
        long long mxV=verticalCuts[0]-0;
        for(int i=1;i<verticalCuts.size();i++){
            long long x=verticalCuts[i];
            long long y=verticalCuts[i-1];
            mxV=max(mxV,x-y);
        }
        mxV=max(mxV,(long long)w-verticalCuts.back());
        return (mxH*mxV)%mod;
    }
};