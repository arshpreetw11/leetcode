class Solution {
public:
    int magicalString(int n) {
        if(n<=0) return 0;
        if(n<=3) return 1;

        string s="122";
        int num=1;
        int count=1;
        int i=2;

        while(s.size()<n){
            int freq = s[i] - '0';
            for (int j = 0; j < freq; j++) {
                s += char('0' + num);
                if (num == 1 && s.size() <= n)
                    count++;
            }
            num=3-num;
            i++;
        }
        count=0;
        for(int j=0;j<n;j++){
            if(s[j]=='1') count++;
        }

        return count;
    }
};