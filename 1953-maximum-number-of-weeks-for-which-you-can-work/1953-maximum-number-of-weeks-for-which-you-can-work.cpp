class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum=0;
        int mx=*max_element(milestones.begin(),milestones.end());

        for(int x: milestones){
            sum+=x;
        }
        long long rest=sum-mx;
        if(mx<=rest+1){
            return sum;
        }
        return (int)(2*rest+1);
    }
};