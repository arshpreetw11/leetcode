class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n=energyDrinkA.size();
        vector<long long> dpA(n,0),dpB(n,0);
        dpA[0]=energyDrinkA[0];
        dpB[0]=energyDrinkB[0];
        for(int i=1;i<n;i++){
            dpA[i]=max(dpA[i-1]+energyDrinkA[i],(i>=2?dpB[i-2]:0)+energyDrinkA[i]);
            dpB[i]=max(dpB[i-1]+energyDrinkB[i],(i>=2?dpA[i-2]:0)+energyDrinkB[i]);
        }
        long long ans=max(dpA[n-1],dpB[n-1]);
        return ans;
    }
};