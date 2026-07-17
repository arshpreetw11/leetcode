class Solution {
public:
    struct Transaction {
        string name;
        int time;
        int amount;
        string city;
        string original;
    };
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n=transactions.size();
        vector<Transaction> tr;

        for(int i=0;i<n;i++){
            string info=transactions[i];
            
                stringstream ss(info);
                string part;
                vector<string> res;

                while (getline(ss, part, ',')) {
                    res.push_back(part);
                }
                tr.push_back({res[0], stoi(res[1]), stoi(res[2]), res[3], info});
            
        }
        n = tr.size();
        vector<bool> invalid(n, false);
        for (int i = 0; i < n; i++) {
            if (tr[i].amount > 1000)
                invalid[i] = true;

            for (int j = i + 1; j < n; j++) {
                if (tr[i].name == tr[j].name &&
                    tr[i].city != tr[j].city &&
                    abs(tr[i].time - tr[j].time) <= 60) {

                    invalid[i] = true;
                    invalid[j] = true;
                }
            }
        }
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            if (invalid[i])
                ans.push_back(tr[i].original);
        }

        return ans;
    }
};