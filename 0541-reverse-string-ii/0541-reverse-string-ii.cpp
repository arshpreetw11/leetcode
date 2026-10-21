class Solution {
public:
    string reverseStr(string s, int k) {
        if(k==1) return s;
        int step=2*k;

        for(int i = 0; i < s.length(); i += step){

            int start = i;
            int end = min(i + k - 1, (int)s.length() - 1);

            while(start < end){
                swap(s[start], s[end]);
                start++;
                end--;
            }
        }
        return s;
    }
};