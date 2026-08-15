class Solution {
public:
    int fillCups(vector<int>& amount) {
        // cold ,warm and hot water
        int mx=0,sum=0;
        for(int &a:amount){
            mx=max(mx,a);
            sum+=a;
        }
        return max(mx,(sum+1)/2);

    }
};