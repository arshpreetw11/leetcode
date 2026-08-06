class Solution {
public:
    bool isPrime(int x){
        if(x<2) return false;
        for(int i=2;i<x;i++){
            if(x%i==0) return false;
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int x: nums){
            freq[x]++;
        }
        for(auto &[x,f]: freq){
            if(isPrime(f)) return true;
        }
        return false;
    }
};