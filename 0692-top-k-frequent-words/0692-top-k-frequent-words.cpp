class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(string &word: words){
            freq[word]++;
        }
        unordered_set<string> ans;
        sort(words.begin(),words.end(),[&](string a,string b){
            if(freq[a]==freq[b]) 
                return a<b;
            return freq[a]>freq[b];
        });
        vector<string> res;
        unordered_set<string> seen;
        for(string &s:words){
            if(!seen.count(s)){
                seen.insert(s);
                res.push_back(s);
            }
            if(res.size()==k) break;
        }
        return res;
    }
};