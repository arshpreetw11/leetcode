class Solution {
public:
    string maximumTime(string time) {
        for(int i=0;i<5;i++){
            char ch=time[i];
            if(ch=='?'){
                if(i==0){
                    if( time[1]=='?' || (time[1]<='3' && time[1]>='0'))
                    time[i]='2';
                    else time[i]='1';

                }else if(i==1){
                    if(time[0]=='1' || time[0]=='0') time[i]='9';
                    else time[i]='3';
                }else if(i==3){
                    time[i]='5';
                }else{
                    time[i]='9';
                }
            }
        }
        return time;
    }
};