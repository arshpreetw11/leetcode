class Solution {
public:
int total;
vector<int> prefix;
    Solution(vector<int>& w) {
        total=0;
        for(int x: w){
            total+=x;
            prefix.push_back(total);
        }
    }
    
    int pickIndex() {
        int r=rand()%total+1;
        return lower_bound(prefix.begin(),prefix.end(),r)-prefix.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */