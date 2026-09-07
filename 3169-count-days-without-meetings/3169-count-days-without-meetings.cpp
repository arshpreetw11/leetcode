class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>> st;
        st.push_back(meetings[0]);
        int n=meetings.size();
        for(int i=1;i<n;i++){
            int prevStart=st.back()[0];
            int prevEnd=st.back()[1];

            int s=meetings[i][0];
            int e=meetings[i][1];

            if(s<=prevEnd){
                st.back()[1]=max(prevEnd,e);
            }
            else{
                st.push_back({s,e});
            }
        }
        int sum=0;
        for(int i=0;i<st.size();i++){
            if(i==0){
                sum+=st[i][0]-0-1;
                continue;
            }
            sum+=st[i][0]-st[i-1][1]-1;
        }
        sum+=days-st.back()[1];
        return sum;
    }
};