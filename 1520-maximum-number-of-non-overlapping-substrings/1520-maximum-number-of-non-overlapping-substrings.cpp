class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int> first(26,n),last(26,-1);
        
        vector<pair<int,int>> intervals;
        for(int i=0;i<n;i++){
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }
        for(int c=0;c<26;c++){
            if(last[c]==-1) continue;
            int l=first[c],r=last[c];
            bool valid=true;
            for(int i=l;i<=r;i++){
                int ch=s[i]-'a';
                if(first[ch]<l){
                    valid=false;
                    break;
                }
                r=max(r,last[ch]);
            }
            if(valid){
                intervals.push_back({l,r});
            }
        }
        sort(intervals.begin(), intervals.end(),
            [](auto &a, auto &b) {
                return a.second < b.second;
            });
        vector<string> ans;
        int prev=-1;
        for(auto &p:intervals){
            int l=p.first;
            int r=p.second;
            if(l>prev){
                ans.push_back(s.substr(l,r-l+1));
                prev=r;
            }
        }
        return ans;
    }
};