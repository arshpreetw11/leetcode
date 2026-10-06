class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0) return false;
        unordered_map<int,int> freq;
        for(int x:nums){
            freq[x]++;
        }
        unordered_set<int> st(nums.begin(),nums.end());
        int num_arr=n/k;
        sort(nums.begin(),nums.end());
        int c=0;
        for(int x:nums){
            bool b =true;
            for(int i=0;i<k;i++){
                if(freq[x+i]<1){
                    b= false;
                    break;
                }
                else {
                    freq[x+i]--;
                    if(freq[x+i]<1) st.erase(x+i);
                }
            }
            if(b) c++;
        }
        return c==num_arr;
    }
};