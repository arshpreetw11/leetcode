class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> temp(deck.begin(),deck.end());
        sort(temp.begin(),temp.end());
        int n=deck.size();
        queue<int> q;
        for(int i=0;i<n;i++){
            q.push(i);
        }
        vector<int> ans(n);
        for(int x: temp){

            int idx=q.front();
            q.pop();
            ans[idx]=x;
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};