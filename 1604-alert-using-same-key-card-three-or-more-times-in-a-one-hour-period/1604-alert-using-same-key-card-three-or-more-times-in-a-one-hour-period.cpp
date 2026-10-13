class Solution {
public:
    int convert(string t){
        int hr=stoi(t.substr(0,2));
        int min=stoi(t.substr(3));
        int total=hr*60 +min;
        return total;

    }
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string,vector<int>> mp;
        for(int i=0;i<keyName.size();i++){
            mp[keyName[i]].push_back(convert(keyTime[i]));
        }
        vector<string> ans;
        for(auto &[n,v]:mp){
            sort(v.begin(),v.end());
            for(int i=2;i<v.size();i++){
                if(v[i]-v[i-2]<=60){
                    ans.push_back(n);
                    break;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};