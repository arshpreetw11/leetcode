class Solution {
public:
    unordered_map<int,int> freq;
    unordered_set<int> generate(int num){
        string s=to_string(num);
        int n=s.size();

        unordered_set<int> res;
        res.insert(num);
        vector<string> oneSwap;
        oneSwap.push_back(s);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string temp=s;
                swap(temp[i],temp[j]);
                oneSwap.push_back(temp);
                res.insert(stoi(temp));
            }
        }
        for (string cur : oneSwap) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    string t = cur;
                    swap(t[i], t[j]);
                    res.insert(stoi(t));
                }
            }
        }
        return res;
    }
    int countPairs(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int num : nums){
            unordered_set<int> all=generate(num);
            for(int x: all){
                ans+=freq[x];
            }
            freq[num]++;
        }
        return ans;
    }
};