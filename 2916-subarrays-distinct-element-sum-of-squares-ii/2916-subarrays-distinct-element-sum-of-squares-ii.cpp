class Solution {
public:
using ll =long long;

int n;
    struct Node{
        ll sum=0;
        ll sq=0;
        ll lazy=0;
    };
    vector<Node> seg;
    const ll MOD = 1e9 + 7;
    void apply(int node,int l,int r,ll x){
        ll len=r-l+1;
        seg[node].sq = (seg[node].sq + 2*x*seg[node].sum
                + len*x%MOD*x) % MOD;
        seg[node].sum = (seg[node].sum + len*x) % MOD;
        seg[node].lazy = (seg[node].lazy + x) % MOD;

    }
    void push(int node,int l,int r){
        if(seg[node].lazy==0 || l==r) return ;

        int mid=(l+r)/2;
        ll x=seg[node].lazy;
        apply(2*node,l,mid,x);
        apply(2*node+1,mid+1,r,x);
        seg[node].lazy=0;
    }
    void update(int node,int l,int r,int ql,int qr,ll x){
        if(ql>r || qr<l) return ;

        if(ql<=l && r<=qr){
            apply(node,l,r,x);
            return ;
        }
        push(node,l,r);
        int mid=(l+r)/2;

        update(node*2,l,mid,ql,qr,x);
        update(node*2+1,mid+1,r,ql,qr,x);

        seg[node].sum=(seg[node*2].sum+seg[node*2+1].sum)%MOD;
        seg[node].sq=(seg[node*2].sq+seg[node*2+1].sq)%MOD;
    }
    int sumCounts(vector<int>& nums) {
        n=nums.size();
        seg.assign(4*n+5,Node());
        unordered_map<int,int> last;
        ll ans=0;
        for(int i=0;i<n;i++){
            int p=last.count(nums[i])?last[nums[i]]:-1;

            update(1,0,n-1,p+1,i,1);

            ans = (ans + seg[1].sq) % MOD;
            last[nums[i]]=i;
        }
        return ans;
    }
};