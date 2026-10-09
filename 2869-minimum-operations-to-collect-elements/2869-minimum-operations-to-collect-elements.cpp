class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int op=0;
        unordered_set<int> st;
        for(int i=1;i<=k;i++){
            st.insert(i);
        }
        int i=nums.size()-1;
        while(st.size()!=0){
            if(st.count(nums[i])) st.erase(nums[i]);
            op++;
            i--;
        }
        return op;
    }
};