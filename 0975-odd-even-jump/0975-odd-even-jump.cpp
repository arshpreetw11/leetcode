class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n=arr.size();
        map<int,int> mp;
        vector<int> nextOdd(n,-1),nextEven(n,-1);
        for(int i=n-1;i>=0;i--){
            int num=arr[i];
            auto it=mp.lower_bound(num);
            if(it!=mp.end()){
                nextOdd[i]=it->second;
            }
            it=mp.upper_bound(num);
            if(it!=mp.begin()){
                --it;
                nextEven[i]=it->second;
            }
            
            mp[arr[i]]=i;
        }
        vector<bool> odd(n),even(n);
        odd[n-1]=true;
        even[n-1]=true;
        for(int i=n-2;i>=0;i--){
            if(nextOdd[i]!=-1){
                odd[i]=even[nextOdd[i]];
            }
            if(nextEven[i]!=-1){
                even[i]=odd[nextEven[i]];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(odd[i]) ans++;
        }
        return ans;
    }
};