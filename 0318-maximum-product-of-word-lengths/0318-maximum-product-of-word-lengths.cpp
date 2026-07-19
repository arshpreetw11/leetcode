class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        int product=0;
        for(int i=0;i<n;i++){
            string word=words[i];
            int len=word.size();
            unordered_map<char,int> freq;
            for(char ch : word){
                freq[ch]++;
            }
            for(int j=i+1;j<n;j++){
                string word2=words[j];
                int len2=word2.size();
                int take=true;
                for(char ch : word2){
                    if(freq[ch]){
                        take=false;
                        break;
                    }
                }
                if(take){
                    product=max(product,len*len2);
                }
            }
        }
        return product;
    }
};