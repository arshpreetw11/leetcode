class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int miss=0;
        unordered_set<int> st(nums.begin(),nums.end());

        int i=1;
        while(true){
            if(!st.count(k*i)){
                return k*i;
            }
            i++;
        }
        return -1;
    }
};