class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        if(n==2){
            return skill[0]*skill[1];
        }
        int teams=n/2;
        sort(skill.begin(),skill.end());
        int l=0,r=n-1;
        long long sum=skill[l]+skill[r];
        long long pdct=skill[l]*skill[r];
        l++;
        r--;
        while(l<r){
            if(sum==skill[l]+skill[r])
            {
                pdct+=skill[l]*skill[r];
            }else{
                return -1;
            }
            l++;
            r--;
        }
        return pdct;
    }
};