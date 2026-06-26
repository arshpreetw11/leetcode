class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        vector<string> words;
        string temp;

        s.push_back(' ');
        for (char c : s) {
            if (c == ' ') {
                words.push_back(temp);
                temp.clear();
            } else {
                temp.push_back(c);
            }
        }

        if (words.size() != pattern.size())
            return false;

        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            string word = words[i];

            if (mp1.count(ch) && mp1[ch] != word)
                return false;

            if (mp2.count(word) && mp2[word] != ch)
                return false;

            mp1[ch] = word;
            mp2[word] = ch;
        }
        return true;
    }
};