class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> prob_users;
        auto common=[&](vector<int> a,vector<int> b){
            unordered_set<int> st(a.begin(),a.end());
            for(int x:b){
                if(st.count(x)) return true;
            }
            return false;
        };
        for(auto &frnd:friendships){
            int u=frnd[0];
            int v=frnd[1];
            if(!common(languages[u-1],languages[v-1])){
                prob_users.insert(u);
                prob_users.insert(v);
            }
        }
        unordered_map<int,int> cnt;

        for(int user : prob_users) {
            for(int lang : languages[user-1]) {
                cnt[lang]++;
            }
        }
        int mx=0;
        for(auto &[l,count]:cnt){
            mx=max(mx,count);
        }
        return prob_users.size()-mx;
    }
};