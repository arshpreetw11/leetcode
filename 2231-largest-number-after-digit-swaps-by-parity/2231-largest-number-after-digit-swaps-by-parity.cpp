class Solution {
public:
    int largestInteger(int num) {
        string n=to_string(num);
        vector<char> odd,even;
        for(int i=0;i<n.size();i++){
            if((n[i]-'0')%2){
                odd.push_back(n[i]);
            }else{
                even.push_back(n[i]);
            }
        }
        sort(odd.rbegin(),odd.rend());
        sort(even.rbegin(),even.rend());

        string res="";
        int o=0,e=0;
        for(char c:n){
            if((c-'0')%2){
                res+=odd[o++];
            }else{
                res+=even[e++];
            }
        }
        return stoi(res);
    }
};