class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return n;
        int mx=0;
        for(int i=0;i<n;i++){
            int k=i;
            while(k+1<n ){
                if(k%2 && arr[k]>arr[k+1])k++;
                else if(k%2==0 && arr[k]<arr[k+1])k++;
                else break;
            }
            mx=max(mx,k-i+1);
        }
        for(int i=0;i<n;i++){
            int k=i;
            while(k+1<n ){
                if(k%2 && arr[k]<arr[k+1])k++;
                else if(k%2==0 && arr[k]>arr[k+1])k++;
                else break;
            }
            mx=max(mx,k-i+1);
        }
        return mx;
    }
};