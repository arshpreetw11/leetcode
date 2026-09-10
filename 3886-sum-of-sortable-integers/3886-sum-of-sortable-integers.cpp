class Solution {
public:
    int minRotation(vector<int>& a) {
        int n = a.size();
        int i = 0, j = 1, k = 0;

        while (i < n && j < n && k < n) {
            int x = a[(i + k) % n];
            int y = a[(j + k) % n];

            if (x == y) {
                k++;
            }
            else if (x > y) {
                i = i + k + 1;
                if (i <= j) i = j + 1;
                k = 0;
            }
            else {
                j = j + k + 1;
                if (j <= i) j = i + 1;
                k = 0;
            }
        }

        return min(i, j);
    }

    bool isRotation(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int start = minRotation(a);
        for (int i = 0; i < n; i++) {
            if (a[(start + i) % n] != b[i])
                return false;
        }

        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        vector<int> sorted=nums;
        sort(sorted.begin(),sorted.end());

        for(int k=1;k<=n;k++){
            if(n%k!=0) continue;
            bool possible=true;

            for(int s=0;s<n;s+=k){
                vector<int> a,b;
                for(int j=s;j<s+k;j++){
                    a.push_back(nums[j]);
                    b.push_back(sorted[j]);
                }
                // sort(a.begin(),a.end());
                // sort(b.begin(),b.end());

                if(!isRotation(a,b)){
                    possible=false;
                    break;
                }
            }
            if(possible)
                ans+=k;
        }
        return ans;
    }
};