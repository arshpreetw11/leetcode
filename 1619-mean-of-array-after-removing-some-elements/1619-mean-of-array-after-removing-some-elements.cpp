class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        double db=0;
        int n=arr.size();
        int rem=n/20;
        for(int i=rem;i<n-rem;i++){
            db+=arr[i];
        }
        db/=(n-2*rem);
        return db;
    }
};