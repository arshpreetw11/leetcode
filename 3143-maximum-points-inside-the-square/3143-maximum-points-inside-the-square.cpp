class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        // sort(points.begin(),points.end(),[&](vector<int>& a,vector<int>& b){
        //     int mx1=max(abs(a[0]),abs(a[1]));
        //     int mx2=max(abs(b[0]),abs(b[1]));
        //     return mx1<mx2;
        // });
        // int mx=0;
        // //for each edge length;
        // for(int i=0;i<points.size();i++){
        //     int x=points[i][0];
        //     int y=points[i][1];
        //     set<char> seen;
        //     int len=max(abs(x),abs(y))*2;
        //     int cnt=0;
        //     for(int j=0;j<points.size();j++){
        //         int a=points[j][0];
        //         int b=points[j][1];
        //         if(abs(a)<=len/2 && abs(b)<=len/2){
        //             if(seen.count(s[j]))
        //                 break;
        //             cnt++;
        //             seen.insert(s[j]);
        //         }
        //     }
        //     mx=max(mx,cnt);
        // }
        // return mx;
        int n=points.size();
        vector<pair<int,char>> v;
        for(int i=0;i<n;i++){
            int d=max(abs(points[i][0]),abs(points[i][1]));
            v.push_back({d,s[i]});
        }
        sort(v.begin(),v.end());
        set<char> seen;
        int ans=0;
        for(int i=0;i<n;){
            int d=v[i].first;
            int j=i;
            set<char> temp;
            while(j<n && v[j].first==d){
                if(seen.count(v[j].second)) return ans;
                if(temp.count(v[j].second)) return ans;

                temp.insert(v[j].second);
                j++;
            }
            for(char c: temp){
                seen.insert(c);
            }
            ans+=temp.size();
            i=j;
        }
        return ans;
    }
};