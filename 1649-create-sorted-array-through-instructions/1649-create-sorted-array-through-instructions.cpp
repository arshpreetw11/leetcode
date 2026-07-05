class Solution {
public:
const int MOD = 1e9 + 7;
    class BIT{
        public:
        vector<int> bit;
        int n;

        BIT(int size) {
            n = size;
            bit.assign(n + 1, 0);
        }
        int query(int idx){
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & (-idx);
            }
            return sum;
        }
        void update(int idx,int val){
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & (-idx);
            }
        }
    };
    
    int createSortedArray(vector<int>& instructions) {
        vector<int> nums;
        int n=instructions.size();
        int mx=*max_element(instructions.begin(),instructions.end());
        BIT ft(mx);
        int cost=0;
        for(int i=0;i<instructions.size();i++){
            int num=instructions[i];
            int less=ft.query(num-1);
            int greater=i-ft.query(num);
            cost = (cost + min(less, greater)) % MOD;
            ft.update(num,1);
        }
        return cost;
    }
};