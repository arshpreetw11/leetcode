class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int> freq;
        for(int n:arr){
            freq[n]++;
        }
        unordered_set<int> st;
        for(auto &[n,f]:freq){
            if(st.count(f)) return false;
            st.insert(f);
        }
        return true;
    }
};