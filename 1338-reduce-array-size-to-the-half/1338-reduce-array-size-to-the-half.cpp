class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> freq,subfreq;
        int n=arr.size();
        for(int a:arr){
            freq[a]++;
        }
        subfreq=freq;
        vector<int> unique;
        for(auto [_,a]:freq){
            unique.push_back(a);
            
        }
        sort(unique.begin(),unique.end());
        int half=n/2;
        int size=0,fr=0,i=unique.size()-1;
        while(fr<half){
            size+=1;
            fr+=unique[i--];
        }
        return size;
    }
};