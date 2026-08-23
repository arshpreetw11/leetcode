class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> freq;
        for(char c:s){
            freq[c]++;
        }
        unordered_set<int> st;
        int ans=0;
        for(auto &[c,f]:freq){
            while(f>0 && st.count(f)){
                f--;
                ans++;
            }
            st.insert(f);
        }

        return ans;
    }
};