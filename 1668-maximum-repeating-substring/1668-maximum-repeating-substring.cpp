class Solution {
public:
    int maxRepeating(string sequence, string word) {
        if(word.size()>sequence.size()) return 0;
        if(word.size()==sequence.size() && word==sequence) return 1;
        int count=0;
        string temp=word;
        while(sequence.find(temp)!=string::npos){
            count++;
            temp+=word;
        }
        return count;
    }
};