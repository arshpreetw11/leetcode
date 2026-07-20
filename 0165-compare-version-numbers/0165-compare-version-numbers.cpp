class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m=version1.size(),n=version2.size();
        vector<int> v1,v2;
        int dots1=0,dots2=0;
        string st="";
        for(int i=0;i<m;i++){
            if(version1[i]=='.') {dots1++;
            v1.push_back(stoi(st));
            st="";
            continue;}
            st+=(version1[i]);
        }
        v1.push_back(stoi(st));
        st="";
        for(int i=0;i<n;i++){
            if(version2[i]=='.') {dots2++;
            v2.push_back(stoi(st));
            st="";
            continue;}
            st+=version2[i];
        }
        v2.push_back(stoi(st));
        int mx = max(v1.size(), v2.size());

        for(int i = 0; i < mx; i++) {
            int a = (i < v1.size()) ? v1[i] : 0;
            int b = (i < v2.size()) ? v2[i] : 0;

            if(a > b) return 1;
            if(a < b) return -1;
        }
        return 0;
    }
};