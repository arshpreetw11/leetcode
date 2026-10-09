class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int num=1;
        for(int t:target){
            if(t==num){
                res.push_back("Push");
                num++;
            }else{
                while(t!=num){
                    res.push_back("Push");
                    res.push_back("Pop");
                    num++;
                }
                res.push_back("Push");
                num++;
            }
        }
        return res;
    }
};