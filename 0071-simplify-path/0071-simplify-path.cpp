class Solution {
public:
    string simplifyPath(string path) {
        vector<string> doc;
        string res_path="";
        
        path += '/'; 
        int cnt=0;
        string s="";
        int n=path.size();
        for(int i=0;i<n;i++){
            
            if(path[i]=='/'){
                
                if(s=="" || s=="."){
                    
                }
                else if(s==".."){
                    if(!doc.empty()){
                        doc.pop_back();
                    }
                    
                }
                else 
                    doc.push_back(s);
                
                s="";
            }
            else{
                s+=path[i];
            }
        }
        for(string &dir : doc){
            res_path += "/" + dir;
        }
        if(res_path.empty()) return "/";
        return res_path;
    }
};