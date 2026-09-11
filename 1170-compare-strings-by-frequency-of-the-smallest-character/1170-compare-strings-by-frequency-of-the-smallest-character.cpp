class Solution {
public:
int f(string s){
    sort(s.begin(),s.end());
    char c=s[0];
    int cnt=0;
    for(char ch:s){
        if(ch!=c)break;
        cnt++;
    }
    return cnt;
}
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int q=queries.size();
        vector<int> res(q,0);
        for(int i=0;i<q;i++){
            string s=queries[i];
            for(string w:words){
                if(f(s)<f(w)) res[i]++;
            }
        }
        return res;
    }
};