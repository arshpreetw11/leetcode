class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        vector<int> position(n);
        for(int i=0;i<n;i++){
            position[row[i]]=i;
        }
        int swaps=0;
        for(int i=0;i<n;i+=2){
            int person=row[i];
            int partner=person^1;

            if(partner==row[i+1]) continue;
            swaps++;
            int partnerPos=position[partner];
            int other=row[i+1];
            swap(row[i+1],row[partnerPos]);
            position[other]=partnerPos;
            position[partner]=i+1;
        }
        return swaps;
    }
};