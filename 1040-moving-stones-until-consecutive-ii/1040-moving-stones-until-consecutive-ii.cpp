class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        int n=stones.size();
        sort(stones.begin(),stones.end());
        int empty=0;
        for(int i=0;i<n-1;i++){
            int e=stones[i+1]-stones[i]-1;
            empty+=e;
        }
        int left=stones[n-2]-stones[0]-(n-2);
        int right=stones[n-1]-stones[1]-(n-2);
        int mxMove=max(left,right);
        int j = 0;
        int maxWindow = 0;

        for (int i = 0; i < n; i++) {
            while (stones[i] - stones[j] + 1 > n)
                j++;

            maxWindow = max(maxWindow, i - j + 1);
        }

        int minMove;
        if ((stones[n - 2] - stones[0] == n - 2 && stones[n - 1] - stones[n - 2] > 2) ||
            (stones[n - 1] - stones[1] == n - 2 && stones[1] - stones[0] > 2)) {
            minMove = 2;
        } else {
            minMove = n - maxWindow;
        }
        return {minMove,mxMove};
    }
};