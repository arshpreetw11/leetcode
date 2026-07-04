class Solution {
public:
    int similarPairs(vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            sort(s.begin(),s.end());
            unordered_set<char> temp(s.begin(),s.end());
            for(int j=i+1;j<words.size();j++){
                string s2=words[j];
                sort(s2.begin(),s2.end());
                unordered_set<char> temp2(s2.begin(),s2.end());
                if(temp==temp2){
                    ans++;
                }
            }
        }
        return ans;
    }
};