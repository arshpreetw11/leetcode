class Solution {
public:
    int hIndex(vector<int>& citations) {
        int totalPapers=citations.size();
        //int diff=INT_MAX,ans=0;
        sort(citations.begin(),citations.end(),greater<int>());
        for(int i=0;i<totalPapers;i++){
            if(citations[i]<i+1){
                return i;
            }
        }
        return totalPapers;
    }
};