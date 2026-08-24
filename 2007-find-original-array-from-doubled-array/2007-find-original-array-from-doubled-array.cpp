class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int dbl=changed.size();
        if(dbl%2) return {};
        int n=dbl/2;

        int find=0;
        unordered_map<int,int> freq;
        for(int x:changed){
            freq[x]++;
        }
        vector<int> ans;
        unordered_set<int> st(changed.begin(),changed.end());
        sort(changed.begin(),changed.end());
        for(int i=0;i<dbl;i++){
            int num=changed[i];
            int dnum=2*num;
            if(st.count(num)){
                if(num==dnum){
                    if(freq[num]>1){
                        freq[num]-=2;
                        ans.push_back(num);
                        if(freq[num]==0)
                        st.erase(num);
                    }
                }
                else{
                    if(st.count(dnum)){
                        freq[dnum]--;
                        freq[num]--;
                        ans.push_back(num);
                        if(freq[dnum]==0) st.erase(dnum);
                        if(freq[num]==0) st.erase(num);

                    }
                }
            }
        }
        if(ans.size()==n) return ans;
        return {};
    }
};