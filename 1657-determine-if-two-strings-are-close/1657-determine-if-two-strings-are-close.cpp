class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int> freq1,freq2;
        for(char ch: word1){
            freq1[ch]++;
        }
        for(char ch: word2){
            freq2[ch]++;
        }
        if(word1==word2) return true;
        for(auto & f: freq1){
            if(freq2.find(f.first)==freq2.end())
                return false;
        }
        for(auto & f: freq2){
            if(freq1.find(f.first)==freq1.end())
                return false;
        }
        vector<int> f1,f2;
        for(auto &f: freq1){
            f1.push_back(f.second);
        }
        for(auto &f: freq2){
            f2.push_back(f.second);
        }
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());
        return f1==f2;
    }
};