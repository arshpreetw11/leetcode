class Solution {
public:
set<char> vowels={'a','e','i','o','u'};
    string sortVowels(string s) {
        int sz=s.size();
        vector<int> freq(26,0),first(26,sz);
        vector<char> v;
        for(int i=0;i<sz;i++){
            char c=s[i];
            if(vowels.count(c)){
                freq[c-'a']++;
                v.push_back(c);
                if(first[c-'a']==sz)
                    first[c-'a']=i;
            }
        }

        sort(v.begin(),v.end(),[&](char a,char b){
            if(freq[a-'a']==freq[b-'a']) return first[a-'a']<first[b-'a'];
            return freq[a-'a']>freq[b-'a']; 
        });
        int j=0;
        for(int i=0;i<sz;i++){
            char c=s[i];
            if(vowels.count(c)){
                s[i]=v[j];
                j++;
            }
        }
        return s;
    }
};