class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string lower(string s) {
        for(char &c : s)
            c = tolower(c);
        return s;
    }

    string normalize(string s) {
        s = lower(s);
        for(char &c : s) {
            if(isVowel(c))
                c = '*';
        }
        return s;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact;
        unordered_map<string, string> lowerMap;
        unordered_map<string, string> vowelMap;

        for(string word : wordlist) {
            exact.insert(word);

            string low = lower(word);

            if(!lowerMap.count(low))
                lowerMap[low] = word;

            string normal = normalize(word);

            if(!vowelMap.count(normal))
                vowelMap[normal] = word;
        }

        vector<string> ans;

        for(string query : queries) {
            if(exact.count(query)) {
                ans.push_back(query);
                continue;
            }
            string low = lower(query);

            if(lowerMap.count(low)) {
                ans.push_back(lowerMap[low]);
                continue;
            }
            string normal = normalize(query);

            if(vowelMap.count(normal)) {
                ans.push_back(vowelMap[normal]);
                continue;
            }
            ans.push_back("");
        }

        return ans;
    }
};