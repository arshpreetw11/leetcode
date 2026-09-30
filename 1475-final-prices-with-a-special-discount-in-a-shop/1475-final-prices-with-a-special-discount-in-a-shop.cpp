class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        for(int i=0;i<n;i++){
            int p=prices[i];
            int j=i+1;
            while(j<n && prices[j]>p){
                j++;
            }
            if(j<n){
                prices[i]=p-prices[j];
            }
        }
        return prices;
    }
};