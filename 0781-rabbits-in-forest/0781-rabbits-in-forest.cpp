class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n=answers.size();
        unordered_map<int,int> freq;
        for(int x: answers){
            freq[x]++;
        }
        sort(answers.begin(),answers.end());
        int cnt=0;
        for(auto &[x,f]:freq){
            int gSize=x+1;
            int g=(f+x)/gSize;
            cnt+=g*gSize;
        }
        return cnt;
    }
};