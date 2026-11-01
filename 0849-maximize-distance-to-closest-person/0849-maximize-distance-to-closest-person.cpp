class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int start=0,end=0;
        int count=0,res=0;
        if(seats[0]==0){
            for(int i=0;i<seats.size();i++){
                if(seats[i]==1){
                    break;
                }else{
                    start++;
                }
                res=max(res,start);
            }
        }
        if(seats[seats.size()-1]==0){
            for(int i=seats.size()-1;i>=0;i--){
                if(seats[i]==1) break;
                else end++;
                res=max(res,end);
            }
        }
        for(int i=0;i<seats.size();i++){
                if(seats[i]==1){
                    count=0;
                }else{
                    count++;
                }
                res=max(res,count);
            }
        if(start==res || end==res) return res;

        if((res+1)/2<start) return start;
        if((res+1)/2<end) return end;
        return (res+1)/2;
    }
};