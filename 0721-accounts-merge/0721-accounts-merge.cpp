class DSU {
public:
    unordered_map<string, string> parent;

    string find(string x) {
        if (parent.find(x) == parent.end())
            parent[x] = x;
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(string x, string y) {
        string px = find(x);
        string py = find(y);
        if (px != py)
            parent[px] = py;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu;
        unordered_map<string, string> emailToName;

        for (auto &acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); i++) {
                emailToName[acc[i]] = name;
                dsu.unite(acc[1], acc[i]); 
            }
        }
        unordered_map<string, vector<string>> groups;
        for (auto &p : emailToName) {
            string parent = dsu.find(p.first);
            groups[parent].push_back(p.first);
        }

        vector<vector<string>> result;
        for (auto &g : groups) {
            vector<string> emails = g.second;
            sort(emails.begin(), emails.end());

            vector<string> account;
            account.push_back(emailToName[g.first]); 
            account.insert(account.end(), emails.begin(), emails.end());

            result.push_back(account);
        }

        return result;
    }
};