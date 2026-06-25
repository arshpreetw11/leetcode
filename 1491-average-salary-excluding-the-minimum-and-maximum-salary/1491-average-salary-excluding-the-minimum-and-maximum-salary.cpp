class Solution {
public:
    double average(vector<int>& salary) {
        double db=0;
        int n=salary.size();
        sort(salary.begin(),salary.end());
        if(n==2) return db;
        for(int i=1;i<n-1;i++){
            db+=salary[i];
        }
        db/=(n-2);
        return db;
    }
};