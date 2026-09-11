class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(int n: nums){
            string s=to_string(n);
            int len=s.size();
            if(len%2==0) cnt++;
        }
        return cnt;
    }
};