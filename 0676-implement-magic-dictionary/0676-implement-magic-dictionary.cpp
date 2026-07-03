class MagicDictionary {
public:
    unordered_set<string> dic;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        int n=dictionary.size();
        for(string dict: dictionary){
            dic.insert(dict);
        }
    }
    
    bool search(string searchWord) {
        for(int i=0;i<searchWord.size();i++){
            char ch=searchWord[i];
            for(char c='a';c<='z';c++){
                if(ch==c) continue;
                searchWord[i]=c;
                if(dic.count(searchWord)){
                    return true;
                }
                searchWord[i]=ch;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */