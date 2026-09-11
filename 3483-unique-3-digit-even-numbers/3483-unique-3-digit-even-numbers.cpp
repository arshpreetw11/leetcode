class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> st;
        int n=digits.size();
        for(int i=0;i<n;i++){
            if(digits[i]%2) continue;

            for(int j=0;j<n;j++){
                if(i==j) continue;

                for(int k=0;k<n;k++){
                    if(k==j || k==i) continue;
                    if(digits[k]==0) continue;
                    int num=digits[k]*100 +digits[j]*10 + digits[i];

                    st.insert(num);
                }
            }
        }
        return st.size();
    }
};