class Solution {
public:
    int check(int n){
        int s=0;
        while(n>1){
            if(n%2){
                n=3*n+1;
            }else{
                n/=2;
            }
            s++;
        }
        return s;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> store;
        for(int i=lo;i<=hi;i++){
            int steps=check(i);
            store.push_back({i,steps});
        }
        sort(store.begin(),store.end(),[&](pair<int,int>& a,pair<int,int>& b){
            if(a.second==b.second){
                return a.first<b.first;
            }
            return a.second<b.second;
        });
        auto x=store[k-1];
        return x.first;
    }
};