class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> pos;
        int n=26;
        for(char c:order){
            pos[c]=n--;
        }
        for(int i=1;i<words.size();i++){
            string a=words[i-1],b=words[i];
            int j=0;
            int mn=min(a.size(),b.size());
            while (j < mn && a[j] == b[j]) {
                j++;
            }
            if (j == mn) {
                if (a.size() > b.size()) return false;
            } else if (pos[a[j]] < pos[b[j]]) {
                return false;
            }
        }
        return true;
    }
};