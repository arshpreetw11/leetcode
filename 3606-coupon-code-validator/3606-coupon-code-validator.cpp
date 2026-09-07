class Solution {
public:
set<string> b={"electronics", "grocery", "pharmacy", "restaurant"};
    bool validCode(string code){
        for(char c:code){
            if(!((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9') ||(c=='_'))){
                return false;
            }
        }
        return true;
    }
    bool validBusiness(string business){
        return b.count(business);
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int coupons=code.size();
        
        vector<pair<string,string>> valid;
        for(int i=0;i<coupons;i++){
            string c=code[i];
            if(c.size()==0) continue;
            string B=businessLine[i];
            bool active=isActive[i];
            if(!active) continue;
            if(validCode(c) && validBusiness(B)){
                valid.push_back({c,B});
            }
        }
        sort(valid.begin(),valid.end(),[](auto &a,auto &b){
            if(a.second==b.second)
                return a.first<b.first;
            return a.second<b.second;
        });
        vector<string> ans;
        for(auto &p:valid){
            ans.push_back(p.first);
        }
        return ans;
    }
};