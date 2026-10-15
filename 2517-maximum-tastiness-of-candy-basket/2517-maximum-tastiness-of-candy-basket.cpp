class Solution {
public:
    bool isPossible(vector<int>& price,int k,int mid){
        int count=1;
        int last=price[0];
        for(int i=1;i<price.size();i++){
            if(price[i]-last>=mid){
                last=price[i];
                count++;
            }
            if(count==k) return true;
        }
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        if(k==2){
            int mx=*max_element(price.begin(),price.end());
            int mn=*min_element(price.begin(),price.end());
            return mx-mn;
        }
        sort(price.begin(),price.end());
        int n=price.size();
        int low=1,high=price[n-1]-price[0];
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(price,k,mid)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};