class Solution {
public:
    string alphabetBoardPath(string target) {
        vector<string> board={"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
        int x=0,y=0;
        string dir="";
        for(char c:target){
            int v=c-'a';
            int i=v/5,j=v%5;
            while(x>i){
                x--;
                dir.push_back('U');
            }
            
            while(j<y){
                y--;
                dir.push_back('L');
            }
            while(x<i){
                x++;
                dir.push_back('D');
            }
                while(j>y){
                    y++;
                    dir.push_back('R');
                }
            
            dir.push_back('!');
        }
        return dir;
    }
};