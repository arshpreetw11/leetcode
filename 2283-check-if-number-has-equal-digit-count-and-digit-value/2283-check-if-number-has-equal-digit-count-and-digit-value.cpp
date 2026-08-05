class Solution {
public:
    bool digitCount(string num) {
        int n=num.size();
        unordered_map<int,int> freq;
        for(char ch: num){
            freq[ch-'0']++;
        }
        for(int i=0;i<num.size();i++){
            if(freq[i]!=num[i]-'0') return false;
        }
        return true;
    }
};