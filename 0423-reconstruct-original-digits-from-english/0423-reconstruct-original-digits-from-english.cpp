class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char,int> freq;
        for(char ch : s){
            freq[ch]++;
        }
        vector<int> res(10, 0);
        res[0]=freq['z'];
        res[2]=freq['w'];
        res[4]=freq['u'];
        res[6]=freq['x'];
        res[8]=freq['g'];
        res[3]=freq['h']-res[8];
    
        res[5]=freq['f']-res[4];
        res[7]=freq['s']-res[6];
        res[1]=freq['o']-res[0]-res[2]-res[4];
        res[9]=freq['i']-res[5]-res[6]-res[8];
        
        string ans = "";
        for (int i = 0; i <= 9; i++) {
            while (res[i]>0) {
                ans += char(i + '0');
                res[i]--;
            }
        }
        return ans;
    }
};