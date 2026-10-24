class Solution {
public:
    int getDay(int month,int day,vector<int>& days){
        int total=day;
        for(int i=0;i<month-1;i++){
            total+=days[i];
        }
        return total;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<bool> present(365,false);
        vector<int> days={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int sMA=stoi(arriveAlice.substr(0,2));
        int sDA=stoi(arriveAlice.substr(3));

        int sMB=stoi(arriveBob.substr(0,2));
        int sDB=stoi(arriveBob.substr(3));

        int eMA=stoi(leaveAlice.substr(0,2));
        int eDA=stoi(leaveAlice.substr(3));

        int eMB=stoi(leaveBob.substr(0,2));
        int eDB=stoi(leaveBob.substr(3)); 

        int sA=getDay(sMA,sDA,days);
        int eA=getDay(eMA,eDA,days);

        int sB=getDay(sMB,sDB,days);
        int eB=getDay(eMB,eDB,days);

        for(int i=sA;i<=eA;i++){
            present[i]=true;
        }
        int count=0;
        for(int i=sB;i<=eB;i++){
            if(present[i]) count++;
        }
        return count;
    }
};