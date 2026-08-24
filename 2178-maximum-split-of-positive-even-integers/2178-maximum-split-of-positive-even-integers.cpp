class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2) return {};

        long long sum=finalSum;
        long long k=2;
        vector<long long> ans;
        while(k<=sum){
            ans.push_back(k);
            sum-=k;
            k+=2;
        }

        if(sum>0){
            ans.back()+=sum;
        }
        return ans;
    }
};