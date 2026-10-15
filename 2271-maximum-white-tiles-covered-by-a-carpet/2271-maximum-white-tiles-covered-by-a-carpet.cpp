class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int n=tiles.size();
        int ans=0,j=0;
        int covered=0;
        sort(tiles.begin(),tiles.end());

        for(int i=0;i<n;i++){
            int carpetEnd=tiles[i][0]+carpetLen-1;

            while(j<n && tiles[j][1]<=carpetEnd){
                covered+=tiles[j][1]-tiles[j][0]+1;
                j++;
            }
            int total=covered;

            if(j<n && tiles[j][0]<=carpetEnd){
                total+=carpetEnd-tiles[j][0]+1;
            }
            ans=max(ans,total);
            if(i<j){
                covered-=tiles[i][1]-tiles[i][0]+1;
            }else 
                j=i+1;
        } 
        return ans;
    }
};