class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> mp;
        vector<int> temp(arr.begin(),arr.end());
        sort(temp.begin(),temp.end());
        int r=1;
        for(int t:temp){
            if(!mp[t]){
                mp[t]=r;
                r++;
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};