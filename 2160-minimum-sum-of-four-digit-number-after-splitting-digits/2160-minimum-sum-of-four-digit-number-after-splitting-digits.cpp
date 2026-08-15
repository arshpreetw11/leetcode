class Solution {
public:
    int minimumSum(int num) {
        int maxSum=0;
        string s=to_string(num);
        vector<char> ch;
        for(int i=0;i<s.size();i++){
            ch.push_back(s[i]);
        }
        sort(ch.begin(),ch.end());
        string new1="";
        new1.push_back(ch[0]);
        new1.push_back(ch[s.size()-1]);
        string new2="";
        new2.push_back(ch[1]);
        new2.push_back(ch[s.size()-2]);
        int a=stoi(new1);
        int b=stoi(new2);
        return a+b;
    }
};