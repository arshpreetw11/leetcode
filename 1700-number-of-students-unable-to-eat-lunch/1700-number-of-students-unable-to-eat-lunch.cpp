class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        queue<int> q;
        for(int i=0;i<n;i++){
            q.push(students[i]);
        }
        int i=0;
        int failed=0;

        while(!q.empty() && failed<q.size()){
            if(q.front()==sandwiches[i]){
                q.pop();
                i++;
                failed=0;
            }
            else{
                int x=q.front();
                q.pop();
                q.push(x);
                failed++;
            }
        }
        return q.size();
    }
};