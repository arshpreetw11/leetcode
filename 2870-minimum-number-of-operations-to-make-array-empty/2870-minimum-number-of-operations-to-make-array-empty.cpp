class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int operations=0;
        unordered_map<int,int> freq;
        for(int x: nums){
            freq[x]++;
        }
        for(auto &[x,f]: freq){
            if(f==1) return -1;
            if(f%3==0)
            operations+=f/3;
            else if(f%3==1){
                operations+=(f/3)-1;
                operations+=2;
            }
            else{
                operations+=(f/3)+1;
            }
        }
        return operations;
    }
};