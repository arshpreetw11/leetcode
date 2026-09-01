class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        //vector<int> next(8,0);
        map<vector<int>,int> mp;
        int day=0;
        while(n>0){

            
            if(mp.count(cells)){
                int cycle=day-mp[cells];
                n%=cycle;
            }
            mp[cells]=day;
            if(n>0){
                vector<int> next(8,0);
                for(int i=1;i<7;i++){
                    if(cells[i-1]==cells[i+1]){
                        next[i]=1;
                    }
                }
                cells=next;
                n--;
                day++;
            }
        }
        return cells;
    }
};