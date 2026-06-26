class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n =nums.size();
        unordered_map<int,int> freqODD,freqEVEN;
        for(int i=0;i<n;i+=2){
            freqEVEN[nums[i]]++;
            if(i+1<n){
                freqODD[nums[i+1]]++;
            }
        }
        vector<pair<int,int>> odd,even;
        for(auto &e : freqEVEN){
            even.push_back({e.second,e.first});
        }

        for(auto &o : freqODD){
            odd.push_back({o.second,o.first});}

        even.push_back({0,-1});
        even.push_back({0,-2});
        odd.push_back({0,-1});
        odd.push_back({0,-2});

        sort(even.rbegin(),even.rend());
        sort(odd.rbegin(),odd.rend());

        if(even[0].second!=odd[0].second){
            return n-even[0].first-odd[0].first;
        }

        return min(n-even[1].first-odd[0].first,
                   n-even[0].first-odd[1].first);
        
    }
};