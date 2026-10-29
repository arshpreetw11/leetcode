class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int f=firstList.size(),s=secondList.size();
        if(f==0 || s==0) return {};
        int i=0,j=0;
        vector<vector<int>> res;
        while(i<f && j<s){
            int start=max(firstList[i][0],secondList[j][0]);
            int end=min(firstList[i][1],secondList[j][1]);
            if(start<=end){
                res.push_back({start,end});
            }
            if(firstList[i][1]<secondList[j][1]){
                i++;
            }else{
                j++;
            }
        }
        return res;
    }
};