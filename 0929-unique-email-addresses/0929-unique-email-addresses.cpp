class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(string email:emails){
            string res="";
            int i=0;
            bool plus=false;
            while(email[i]!='@'){
                if(email[i]=='+'){
                    plus=true;
                    i++;
                    continue;
                }
                if(plus || email[i]=='.'){
                    i++;
                    continue;
                }
                
                res+=email[i];
                i++;
            }
            while(i<email.size()){
                res+=email[i];
                i++;
            }
            st.insert(res);
        }
        return st.size();
    }
};