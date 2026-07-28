class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        vector<int> pairs;
        sort(potions.begin(),potions.end());
        for(int spell: spells){
            int l=0,r=m-1;
            int idx=-1;
            while(l<=r){
                
                int mid=l+(r-l)/2;
                if(1LL * spell * potions[mid]>=success){
                    idx=mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }if(idx!=-1)
            pairs.push_back(m-idx);
            else pairs.push_back(0);
        }
        return pairs;
    }
};