class Solution {
public:
    long long smallestNumber(long long num) {
        string sub="";
        if(num==0) return num;
        if(num<0){
            sub=to_string(num);
            sub=sub.substr(1);
            sort(sub.rbegin(),sub.rend());
            return -stoll(sub);
        }
        sub=to_string(num);
        sort(sub.begin(),sub.end());
        int i=0;
        while(i<sub.size() && sub[i]=='0'){
            i++;
        }
        swap(sub[i],sub[0]);
        return stoll(sub);
    }
};