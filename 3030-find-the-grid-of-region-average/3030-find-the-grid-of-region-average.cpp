class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int m=image.size(),n=image[0].size();
        vector<vector<int>> sum(m,vector<int>(n,0));  //updated by adding the avg sum 
        vector<vector<int>> num(m,vector<int>(n,0));  // incresed by value if we passed from that cell;

        for(int i=0;i<=m-3;i++){
            for(int j=0;j<=n-3;j++){
                long long s=0;
                bool ok=true;
                for(int x=i;x<i+3 && ok;x++){
                    for( int y=j;y<j+3 && ok ; y++){
                        if(y+1<j+3 && abs(image[x][y]-image[x][y+1])>threshold){
                            ok=false;
                        }
                        if(x+1<i+3 && abs(image[x][y]-image[x+1][y])>threshold){
                            ok=false;
                        }
                    }
                }
                if(!ok) continue;
                for(int dx=0;dx<3;dx++){
                    for(int dy=0;dy<3;dy++){
                        int x=i+dx;
                        int y=j+dy;
                        
                        s+=image[x][y];
                        num[x][y]++;
                    }
                }
                for(int dx=0;dx<3;dx++){
                    for(int dy=0;dy<3;dy++){
                        int x=i+dx;
                        int y=j+dy;
                        sum[x][y]+=s/9;
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(num[i][j]==1) continue;
                if(num[i][j]==0) sum[i][j]=image[i][j];
                else
                sum[i][j]/=num[i][j];
            }
        }
        return sum;
    }
};