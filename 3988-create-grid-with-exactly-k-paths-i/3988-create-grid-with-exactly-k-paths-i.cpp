class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {
        if((m==1 || n==1 ) && k>1) return {};
        //int i=0,j=0;
        vector<string> ans(m,string(n,'#'));
        
        if(k==1){
            int i=0,j=0;
            while(j<n){
                ans[0][j]='.';
                j++;
            }
            while(i<m){
                ans[i][n-1]='.';
                i++;
            }
            
        }
        if(k==2){
            //2*2 sub matrix;
            if(m<2 || n<2) return {};
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    ans[i][j]='.';
                }
            }
            int x=1,y=1;
            while(y<n){
                ans[x][y]='.';
                y++;
            }
            while(x<m){
                ans[x][n-1]='.';
                x++;
            }
            
        }
        if(k==3){
            bool valid=false;
            if(m>=2 && n>=3){
                valid=true;
                for(int i=0;i<2;i++){
                    for(int j=0;j<3;j++){
                        ans[i][j]='.';
                    }
                }
                int x=1,y=2;
                while(y<n){
                    ans[x][y]='.';
                    y++;
                }
                while(x<m){
                    ans[x][n-1]='.';
                    x++;
                }
            }else if(m>=3 && n>=2){
                valid=true;
                for(int i=0;i<3;i++){
                    for(int j=0;j<2;j++){
                        ans[i][j]='.';
                    }
                }
                int x=2,y=1;
                while(y<n){
                    ans[x][y]='.';
                    y++;
                }
                while(x<m){
                    ans[x][y-1]='.';
                    x++;
                }
            }
            if(!valid) return {};
        }
        if(k==4){
            bool valid=false;
            if(m >= 3 && n >= 3 ){
                valid = true;
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        ans[i][j] = '.';
                    }
                }
                ans[0][2] = '#';
                ans[2][0] = '#';
                int x = 2, y = 2;
                while(y < n){
                    ans[x][y] = '.';
                    y++;
                }
                while(x < m){
                    ans[x][n-1] = '.';
                    x++;
                }
            }
            else if(m>=2 && n>=4){
                valid=true;
                for(int i=0;i<2;i++){
                    for(int j=0;j<4;j++){
                        ans[i][j]='.';
                    }
                }
                int x=1,y=3;
                for (int j = 3; j < n; j++)
                    ans[1][j] = '.';

                for (int i = 2; i < m; i++)
                    ans[i][n - 1] = '.';
            }else if(m>=4 && n>=2){
                valid=true;
                for(int i=0;i<4;i++){
                    for(int j=0;j<2;j++){
                        ans[i][j]='.';
                    }
                }
                int x=3,y=1;
                for (int j = 1; j < n; j++)
                    ans[x][j] = '.';

                for (int i = 3; i < m; i++)
                    ans[i][n - 1] = '.';
            }
            if(!valid) return {};
        }    
        return ans;
    }
};