class Solution {
public:
    int maxProduct(int n) {
        vector<int>res;
        while(n!=0){
            int num=n%10;
            res.push_back(num);
            n/=10;
        }
        int sz=res.size();
        sort(res.begin(),res.end(),greater<int>());
        int pr=res[0]*res[1];
        return pr;
    }
};