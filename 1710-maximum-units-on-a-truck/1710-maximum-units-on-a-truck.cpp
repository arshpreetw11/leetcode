class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>& a,vector<int>& b){
            return a[1]>b[1];
        });
        int val=0;
        for(auto & it:boxTypes){
            if (truckSize == 0)
                break;
            int take=min(it[0],truckSize);
            truckSize-=take;
            val+=take*it[1];
        }
        return val;
    }
};