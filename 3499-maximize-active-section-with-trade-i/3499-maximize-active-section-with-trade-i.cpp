class Solution {
public:
    struct Block{
        char ch;
        int l,r;
    };
    int maxActiveSectionsAfterTrade(string s) {
        
        int n=s.size();
        int mx=0;
        int i=0,total=0;
        vector<Block> seg;
        for(int j=0;j<n;j++){
            if(s[j]=='1'){
                total++;
            }
        }
        while(i<n){
            int start=i;
            char ch=s[i];
            while(i<n && ch==s[i]){
                i++;
            }
            seg.push_back({ch,start,i-1});
        }
        for(i=0;i<seg.size();i++){
            if(seg[i].ch!='1') continue;
            if(i>0 && i+1<seg.size() && seg[i-1].ch=='0' && seg[i+1].ch=='0'){
                int left=seg[i-1].r-seg[i-1].l+1;
                int right=seg[i+1].r-seg[i+1].l+1;
                int cur=seg[i].r-seg[i].l+1;
                int ones=left+cur+right;
                mx=max(mx,total+left+right);
            }
        }
        return max(mx,total);
    }
};