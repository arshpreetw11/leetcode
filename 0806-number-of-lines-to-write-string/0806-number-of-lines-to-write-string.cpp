class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines=0;
        int sum=0;
        for(char ch:s){
            if(sum+widths[ch-'a']>100){
                lines++;
                sum=0;
            }
            sum+=widths[ch-'a'];
        }
        return {lines+1,sum};
    }
};