class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long totalways=0;
        for(int pens=0;(long long)pens*cost1<=total;pens++){
            long long rem=total-((long long)pens*cost1);
            long long pencil=(rem/cost2)+1;
            totalways+=pencil;
        }
        return totalways;
    }
};