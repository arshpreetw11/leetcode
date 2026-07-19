class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        int product=0;
        sort(words.begin(),words.end(),[&](string &a,string &b){
            if(a.size()==b.size()) return a>b;
            return a.size()>b.size();
        });
        vector<int> bit(n,0);
        for(int i=0;i<n;i++){
            string word=words[i];
            int len=word.size();
            int mask=0;
            for(char c: word){
                mask |=1<<(c-'a');
            }
            bit[i]=mask;
        }
        for(int i=0;i<n;i++){
            int mask1=bit[i];
            int len=words[i].size();
            for(int j=i+1;j<n;j++){
                int mask2=bit[j];
                int len2=words[j].size();
                if((mask1 & mask2)==0){
                    product=max(product,len*len2);
                    break;
                }
            }
        }
        return product;
    }
};