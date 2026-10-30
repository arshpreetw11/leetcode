class Solution {
public:
    string reformatDate(string date) {
        vector<string> mon={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        unordered_map<string,int> mp;
        for(int i=0;i<12;i++){
            mp[mon[i]]=i+1;
        }
        string day="",m="",year="";
        int n = date.size();
        int i=0;
        while(date[i]!=' '){
            day+=date[i];
            i++;

        }
        i++;
        while(date[i]!=' '){
            m+=date[i];
            i++;

        }
        i++;
        while(i<n){
            year+=date[i];
            i++;
        }
        string ans="";
        ans+=year+"-";
        if(mp[m]<10) ans+="0"+to_string(mp[m])+"-";
        else ans+=to_string(mp[m])+"-";
        if(day.size()==3)day="0"+day;
        ans+= day.substr(0, day.size() - 2);
        return ans;
        
        

        

    }
};