class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h=0;
        
        int n=citations.size();
        sort(citations.begin(),citations.end(),greater<int>());
        for(int idx=1;idx<=n;idx++){
            int val=0;
            for(int i=0;i<n;i++){
                if(citations[i]>=idx){
                    val++;
                    if(val>=idx){
                        h=idx;
                        break;
                    }
                }
                else{
                    if(val<idx){
                        val=0;
                        break;
                    }
                }
            }
            if(val==0) break;
        }
        return h;
    }
};