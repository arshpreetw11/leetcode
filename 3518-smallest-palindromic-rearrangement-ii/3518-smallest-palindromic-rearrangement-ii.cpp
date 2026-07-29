class Solution {
public:
    const long long LIM = 1000005;

long long nCr(int n, int r){
    if(r > n || r < 0) return 0;

    r = min(r, n - r);

    long long ans = 1;

    for(int i = 1; i <= r; i++){
        ans = ans * (n - r + i) / i;
        ans = min(ans, LIM);
    }

    return ans;
}

long long permutation(unordered_map<char,int> &half){

    int len = 0;

    for(auto &[ch,f] : half)
        len += f;

    long long ways = 1;

    for(auto &[ch,f] : half){

        if(f == 0) continue;

        ways *= nCr(len, f);
        ways = min(ways, LIM);

        len -= f;
    }

    return ways;
}
    string smallestPalindrome(string s, int k) {
        int n=s.size();
        
        unordered_map<char,int> freq,half;
        for(char ch :s){
            freq[ch]++;
        }
        for(auto &[ch,f]: freq){
            half[ch]=f/2;
        }
        if(permutation(half)<k) return "";
        string res;
        for(char ch='a';ch<='z';ch++){
            res.append(half[ch],ch);
        }
        string first="";
        for(int pos=0;pos<(n/2);pos++){
            for(char ch='a';ch<='z';ch++){
                if(half[ch]==0) continue;
                half[ch]--;
                long long ways=permutation(half);
                if(ways>=k){
                    first+=ch;
                    break;
                }
                k-=ways;
                half[ch]++;
            }
        }
        char mid=0;
        for(auto &[ch,f]:freq){
            if(f%2){
                mid=ch;
                break;
            }
        }
        string ans=first;
        if(n%2) ans+=mid;
        reverse(first.begin(),first.end());
        ans+=first;
        return ans;
        // string res(s.begin(),s.begin()+n/2);
        // sort(res.begin(),res.end());//k==1;
        // // if(k==1){
        // //     if(n%2) res+=s[n/2];
        // //     string temp=res;
        // //     reverse(temp.begin(),temp.end());
        // //     res+=temp;
        // //     return res;
        // // // }
        // while (--k) {
        //     if(!next_permutation(res.begin(),res.end())) return "";
        // }
        // string ans=res;
        
        // if(n%2){
        //     ans+=s[n/2];
        // }
        // reverse(res.begin(),res.end());
        // ans+=res;
        // return ans;
    }
};