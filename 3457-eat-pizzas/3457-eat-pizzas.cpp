class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        int n=pizzas.size();
        int days=n/4;
        if(days==1) 
            return *max_element(pizzas.begin(),pizzas.end());
        long long sum=0;
        sort(pizzas.begin(),pizzas.end());
        int i=0;
        int j=n-1;
        int odd=(days%2)?days/2+1:days/2;
        int even=days-odd;
        while(odd--){
            sum+=pizzas[j];
            j--;
        }
        j-=1;
        while(even--){
            sum+=pizzas[j];
            j-=2;
        }
        return sum;
    }
};