class Solution {
public:
    int minTimeToType(string word) {
        int curr=0;
        int sec=0;
        
        for(char c:word){
            int target=c-'a';
            int d=abs(curr-target);
            sec+=min(d,26-d)+1;
            curr=target;
        }
        return sec;
    }
};