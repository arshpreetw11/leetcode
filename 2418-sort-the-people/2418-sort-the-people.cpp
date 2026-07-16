class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        for(int i=0;i<n;i++){
            int mx=heights[i];
            int idx=i;
            for(int j=i+1;j<n;j++){
                if(mx<heights[j]){
                    mx=heights[j];
                    idx=j;
                }
            }
            swap(names[i],names[idx]);
            heights[idx]=-1;
            swap(heights[i],heights[idx]);
        }
        return names;
    }
};