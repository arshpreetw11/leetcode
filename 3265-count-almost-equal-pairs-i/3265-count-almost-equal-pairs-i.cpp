class Solution {
public:
    bool check(int x,int y){
        if(x==y) return true;
        string X=to_string(x);
        string Y=to_string(y);
        while(X.size()<Y.size()){
            X='0'+X;
        }
        while(Y.size()<X.size()){
            Y='0'+Y;
        }
        int n=X.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string temp=X;
                swap(temp[i],temp[j]);
                if(temp==Y) return true;
            }
        }
        return false;
    }
    int countPairs(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(check(nums[i],nums[j])){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};