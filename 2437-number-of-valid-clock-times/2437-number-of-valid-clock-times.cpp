class Solution {
public:
    int countTime(string time) {
        int t=1;
        if(time[3]=='?') t*=6;
        if(time[4]=='?') t*=10;

        string hr=time.substr(0,2);
        if(hr=="??") t*=24;
        if(time[0]=='?' && time[1]!='?'){
            if(time[1]>='4' && time[1]<='9') t*=2;
            else t*=3;
        }
        if(time[1]=='?' && time[0]!='?'){
            if(time[0]>='0' && time[0]<='1') t*=10;
            else t*=4;
        }
        return t;
    }
};