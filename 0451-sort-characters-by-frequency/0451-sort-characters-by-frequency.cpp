class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;

        for(char ch:s){
            freq[ch]++;
        }

        vector<char> chars;
        for(auto &p : freq) {
            chars.push_back(p.first);
        }
        sort(chars.begin(), chars.end(), [&](char a, char b) {
        return freq[a] > freq[b];
        });
        string result = "";
        for (char c : chars) {
            result += string(freq[c], c);
        }
        return result;
    }
};