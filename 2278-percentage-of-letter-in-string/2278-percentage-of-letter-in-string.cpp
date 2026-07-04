class Solution {
public:
    int percentageLetter(string s, char letter) {
        unordered_map<char,int> freq;
        bool exist=false;
        int n=s.size();
        for(char c:s){
            freq[c]++;
            if(c==letter) exist=true;
        }
        if(exist){
            return (freq[letter]*100/n);
        }
        return 0;
    }
};