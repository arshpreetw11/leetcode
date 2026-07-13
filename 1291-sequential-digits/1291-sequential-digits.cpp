class Solution {
public:
bool seq(int num){
    int x=num%10;
    num/=10;
    while(num){
        int mod=num%10;
        if(x!=mod+1) return false;
        x=mod;
        num/=10;
    }
    return true;
}
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        //sequential digits;
        string s="123456789";
        for(int len=2;len<=9;len++){
            for(int i=0;i+len<=9;i++){
                int num=stoi(s.substr(i,len));
                if(num>=low && num<=high) res.push_back(num);
            }
        }
        return res;
    }
};