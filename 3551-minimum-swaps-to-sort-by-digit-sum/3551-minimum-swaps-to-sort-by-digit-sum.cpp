class Solution {
public:
    int sumDigits(int num){
        int sum=0;
        while(num!=0){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        vector<tuple<int,int,int>> store;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            int sum=sumDigits(n);
            store.push_back({sum,n,i});
        }
        sort(store.begin(),store.end());
        vector<bool> visited(nums.size(),false);
        int n=nums.size();
        int swaps=0;
        for(int i=0;i<n;i++){
            if(visited[i]||get<2>(store[i])==i){
                visited[i]=true;
                continue;
            }
            int j=i;
            int cycle=0;
            while(!visited[j]){
                visited[j]=true;
                j=get<2>(store[j]);
                cycle++;
            }
            if(cycle>1) swaps+=cycle-1;

        }
        return swaps;
    }
};