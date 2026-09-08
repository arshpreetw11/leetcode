class Solution {
public:
    int countCommas(int n) {
        //starting num==1,000;
        if(n<1000) return 0;
        int commas=n-1000+1;
        
        return commas;
    }
};