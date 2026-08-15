class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<string,int> score;
        for(string s:positive_feedback){
            score[s]=3;
        }
        for(string s:negative_feedback){
            score[s]=-1;
        }
        vector<vector<int>> total;
        int i=0;
        for(int i=0;i<report.size();i++){
            stringstream ss(report[i]);
            string word;
            int val = 0;

            while (ss >> word) {
                if (score.find(word) != score.end())
                    val += score[word];
            }

            total.push_back({student_id[i], val});
        }
        sort(total.begin(),total.end(),[&](const vector<int>&a,const vector<int>&b){
            if(a[1]==b[1]){
                return a[0]<b[0];
            }
            return a[1]>b[1];
        });
        vector<int> res;
        int x=1;
        for(auto & t:total){
            if(x>k)break;
            int id=t[0];
            res.push_back(id);
            x++;
        }
        return res;
    }
};