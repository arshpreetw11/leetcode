class Solution {
public:
    unordered_map<string,int> dp;
    string getKey(string board,unordered_map<char,int> & hand){
        string key=board+"#";
        for(char c='A'; c<='Z'; c++){
            key += c;
            key += to_string(hand[c]);
        }
        return key;
    }

    string shrink(string s){
        while(true){
            string res="";
            int i=0;
            while(i<s.size()){
                int j=i;
                while(j<s.size() && s[i]==s[j])
                    j++;
                if(j-i<3)
                    res+=s.substr(i,j-i);
                i=j;
            }
            if(res.size()==s.size())
                return res;
            s=res;
        }
        return "";
    }
    int dfs(string board,unordered_map<char,int>& hand){
        board=shrink(board);

        if(board.empty()) return 0;
        string key=getKey(board,hand);

        if(dp.count(key)) return dp[key];

        int ans=INT_MAX;
        for(char ch='A';ch<='Z';ch++){
            if(hand[ch]==0) continue;
            hand[ch]--;
            for(int i=0;i<=board.size();i++){
                bool useful=false;

                if(i<board.size() && board[i]==ch) 
                    useful =true;

                if(i>0 && i<board.size() && board[i-1]==board[i] && board[i]!=ch)
                     useful=true;

                if(!useful) continue;
                if (i > 0 && board[i - 1] == ch)
                    continue;
                string next=board;
                next.insert(next.begin()+i,ch);
                next=shrink(next);

                int temp=dfs(next,hand);
                if(temp!=INT_MAX)
                ans=min(ans,1+temp);
            }
            hand[ch]++;
        }
        return dp[key]=ans;
    }

    int findMinStep(string board, string hand) {
        unordered_map<char,int> freq;
        for(char ch: hand){
            freq[ch]++;
        }
        int val=dfs(board,freq);
        if(val==INT_MAX) return -1;
        return val;
    }
};