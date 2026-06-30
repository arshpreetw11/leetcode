class Solution {
public:
bool isVowel(char a){
    return a=='a' || a=='e' || a=='i' || a=='o' || a=='u';
}
    long long countVowels(string word) {
        long long cnt=0;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(isVowel(word[i])){
                cnt+=1LL*(i+1)*(n-i);
            }
        }
        return cnt;
    }
};