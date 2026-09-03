class Solution {
public:
    int convertTime(string current, string correct) {
        int hr1=stoi(current.substr(0,2));
        int hr2=stoi(correct.substr(0,2));
        int min1=stoi(current.substr(3));
        int min2=stoi(correct.substr(3));

        int t1=hr1*60 + min1;
        int t2=hr2*60 + min2;
        int diff=t2-t1;
        int ans=0;

        ans+=diff/60;
        diff%=60;

        ans+=diff/15;
        diff%=15;

        ans+=diff/5;
        diff%=5;

        ans+=diff;
        return ans;
    }
};