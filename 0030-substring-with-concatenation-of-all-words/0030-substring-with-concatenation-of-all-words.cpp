class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len=words[0].size();
        int k=words.size();
        int window=len*k;
        unordered_map<string,int> freq;
        for(string str: words){
            freq[str]++;
        }
        vector<int> ans;
        
        for (int i = 0; i + window <= s.size(); i++) {
            unordered_map<string, int> seen;
            for (int j = 0; j < k; j++) {
                string word = s.substr(i + j * len, len);
                seen[word]++;
            }
            if(seen==freq) ans.push_back(i);
        }
        return ans;
    }
};