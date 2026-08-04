class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> freq;
        unordered_set<string> ban(banned.begin(),banned.end());
        int i=0;
        string word="";
        int n=paragraph.size();
        for(int i=0;i<n;i++){
            char ch = paragraph[i];
            if (isalpha(ch)) {
                word += tolower(ch);
            } else {
                if (!word.empty()) {
                    if (!ban.count(word)) {
                        freq[word]++;
                    }
                    word = "";
                }
            }
        }
        if (!word.empty() && !ban.count(word)) {
            freq[word]++;
        }

        int mx = 0;
        string ans = "";
        
        for (auto &p : freq) {
            if (p.second > mx) {
                mx = p.second;
                ans = p.first;
            }
        }
        return ans;
    }
};