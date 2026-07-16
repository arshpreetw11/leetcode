class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<vector<int>> CP(n);
        for(int i=0;i<n;i++){
            int p=profits[i];
            int c=capital[i];
            CP[i]={c,p};
        }
        sort(CP.begin(),CP.end(),[&](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        int i=0;
        priority_queue<int> pq;
        while(k--){
            while(i<n && CP[i][0]<=w){
                pq.push(CP[i][1]);
                i++;
            }
            if(pq.empty()){
                break;
            }
            w+=pq.top();
            pq.pop();

        }
        return w;
    }
};