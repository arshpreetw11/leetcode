class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {

        vector<int> add;
        while(k!=0){
            int rem=k%10;
            add.push_back(rem);
            k/=10;
        }
        reverse(add.begin(),add.end());
        vector<int> arr;
        int rl=add.size()-1;
        int rn=num.size()-1;
        int carry=0;
        while(rl>=0 ||rn>=0 || carry){
            int sum=carry;
            if(rl>=0) sum+=add[rl--];
            if(rn>=0) sum+=num[rn--];

            arr.push_back(sum%10);
            carry=sum/10;
        }
        
        reverse(arr.begin(),arr.end());
        return arr;
    }
};