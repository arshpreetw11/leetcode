class Solution {
public:
    int dayOfYear(string date) {
        int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        int day=stoi(date.substr(8));
        int mon=stoi(date.substr(5,2));
        int year=stoi(date.substr(0,4));
        
        int total=0;
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            days[1]=29;
        }
        for(int i=0;i<mon-1;i++){
            total+=days[i];
        }
        total+=day;
        return total;
    }
};