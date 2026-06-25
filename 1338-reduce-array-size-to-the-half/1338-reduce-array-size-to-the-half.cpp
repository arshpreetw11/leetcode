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
        for(int a:arr){
            if(subfreq[a]==0) continue;
            unique.push_back(a);
            subfreq[a]=0;
        }
        sort(unique.begin(),unique.end(),[&](int a,int b){
            return freq[a]>freq[b];
        });
        int half=n/2;
        int size=0,fr=0;
        for(int u:unique){
            fr+=freq[u];
            if(fr<half) size++;
            else{
                size++;
                break;
            }
        }
        return size;
    }
};