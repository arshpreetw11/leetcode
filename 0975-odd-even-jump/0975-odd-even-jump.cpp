class Solution {
public:
    int cnt=0;
    
    bool isPos(int i,vector<int>& arr,vector<int>& vis,bool odd,int f){
        if(i==f) return true;
        if(vis[i]) return false;
        vis[i]=1;
        int next=-1;
        if(odd){
            int best = INT_MAX;
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[j] >= arr[i] && arr[j] < best) {
                    best = arr[j];
                    next = j;
                }
            }
        }else{
            int best = INT_MIN;
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[j] <= arr[i] && arr[j] > best) {
                    best = arr[j];
                    next = j;
                }
            }
        }
        if(next==-1) return false;
        return isPos(next,arr,vis,!odd,f);
    }
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