class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int m=score.size(),n=score[0].size();
        vector<int> marks;
        sort(score.begin(),score.end(),[&](vector<int>& a,vector<int>& b){
            return a[k]>b[k];
        });
        // for(int i=0;i<m;i++){
        //     int sc=score[i][k];
        //     marks.push_back(sc);
        // }
        // sort(marks.begin(),marks.end(),greater<int>());
        // for(int i=0;i<m;i++){
        //     score[i][k]=marks[i];
        // }
        return score;
    }
};