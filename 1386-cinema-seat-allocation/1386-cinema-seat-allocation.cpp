class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>> mp;
        for(auto res: reservedSeats){
            int row=res[0];
            int col=res[1];
            mp[row].insert(col);
        }
        int ans=(n-mp.size())*2;
        for(auto &[r,s]:mp){
            bool left=true,mid=true,right=true;
            for(int i=2;i<=5;i++){
                if(s.count(i)){
                    left=false;
                    break;
                }
            }
            for(int i=4;i<=7;i++){
                if(s.count(i)){
                    mid=false;
                    break;
                }
            }
            for(int i=6;i<=9;i++){
                if(s.count(i)){
                    right=false;
                    break;
                }
            }
            if(left && right){
                ans+=2;
            }
            else if(left ||mid|| right){
                ans++;
            }
            else{
                ans+=0;
            }
        }
        return ans;
    }
};