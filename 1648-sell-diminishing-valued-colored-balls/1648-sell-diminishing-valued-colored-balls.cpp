class Solution {
public:
    long long sum(long long l,long long r){
        return (l+r)*(r-l+1)/2;
    }
    int maxProfit(vector<int>& inventory, int orders) {
        int n=inventory.size();
        long long ans=0;
        int count=0;
        int i=0;
        int mod=1e9+7;
        sort(inventory.begin(),inventory.end(),greater<int>());
        while(i<n && orders>0){
            int max=inventory[i];
            int j=i;
            while(j<n && inventory[j]==max){
                j++;
            }
            int next=(j<n)?inventory[j]:0;
            count=j;
            long long items=(long long)(max-next)*count;
            if(orders>=items){
                ans+=sum(next+1,max)*count;
                ans%=mod;
                orders-=items;
                i=j;
            }
            else{
                long long full=orders/count;
                long long rem=orders%count;

                ans+=sum(max-full+1,max)*count;
                ans%=mod;

                ans+=(max-full)*rem;
                ans%=mod;
                break;
            }
        }
        return ans;
    }
};