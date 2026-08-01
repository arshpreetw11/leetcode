class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int m=(n-1)/2;
        m=arr[m];
        sort(arr.begin(),arr.end(),[&](int a,int b){
            if(abs(a-m)==abs(b-m)) 
                return a>b;
            return abs(a-m)>abs(b-m);
        });
        return vector<int>(arr.begin(),arr.begin()+k);
    }
};