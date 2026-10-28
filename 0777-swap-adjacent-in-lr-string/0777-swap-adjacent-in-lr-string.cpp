class Solution {
public:
    bool canTransform(string start, string result) {
        unordered_map<char,int> f1,f2;
        for(char c:start){
            f1[c]++;
        }
        for(char c:result){
            f2[c]++;
        }
        int i=0,j=0;
        int n=start.size();
        while(i<n && j<n){
            while(i<n && start[i]=='X') i++;
            while(j<n && result[j]=='X') j++;

            if(i==n && j==n) return true;
            if(i==n || j==n) return false;
            if(start[i]!=result[j]) return false;
            if (start[i] == 'L' && i < j) {
                return false;
            }
            if (start[i] == 'R' && i > j) {
                return false;
            }
            i++;
            j++;
        }
        while (i < n) {
            if (start[i] != 'X') return false;
            i++;
        }
        while (j < n) {
            if (result[j] != 'X') return false;
            j++;
        }
        return true;
    }
};