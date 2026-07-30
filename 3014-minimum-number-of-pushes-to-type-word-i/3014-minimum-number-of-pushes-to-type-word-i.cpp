class Solution {
public:
    int minimumPushes(string word) {
        int inc=0;
        int sz=word.size();
        int i=0,type=0;
        while(i<sz){
            if(i%8==0){
                inc++;
            }
            type+=inc;
            i++;
        }
        return type;
    }
};