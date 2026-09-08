class Solution {
public:
    bool isPrime(long long x){
        if(x<=1) return false;
        for(long long i=2;i*i<=x;i++){
            if((x%i)==0) 
                return false;
        }
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        set<long long> st;
        long long sum=0;
        for(int i=0;i<s.size();i++){
            long long num=0;
            for(int j=i;j<s.size();j++){
                num=num*10 +(s[j]-'0');
                if(isPrime(num)){
                    st.insert(num);
                }
            }
        }
        int cnt=0;
        for(auto it=st.rbegin();it!=st.rend() && cnt<3;it++){
            sum+=*it;
            cnt++;
        }
        return sum;
    }
};