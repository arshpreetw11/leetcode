class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<int,string> keyboard(3);
        keyboard[0]="qwertyuiop";
        keyboard[1]="asdfghjkl";
        keyboard[2]="zxcvbnm";

        vector<string> res;
        for(string s:words){
            string temp = s;
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            int row;

            for(int i = 0; i < 3; i++) {
                if(keyboard[i].find(temp[0]) != string::npos) {
                    row = i;
                    break;
                }
            }
            bool ok=true;
            for(char ch : temp){
                if(keyboard[row].find(ch) == string::npos) {
                    ok=false;
                    break;
                }
            }
            if(ok) res.push_back(s);
        }
        return res;
    }
};