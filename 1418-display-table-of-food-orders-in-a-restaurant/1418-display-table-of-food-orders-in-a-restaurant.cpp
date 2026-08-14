class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<string> table,food_item;
        map<pair<string,string>,int> mp;
        for(auto &order:orders){
            string t=order[1];
            string food=order[2];
            table.push_back(t);
            food_item.push_back(food);
            mp[{t,food}]++;
        }
        
        sort(table.begin(),table.end(),[&](string a,string b){
            return stoi(a)<stoi(b);
        });
        sort(food_item.begin(),food_item.end());
        table.erase(unique(table.begin(),table.end()),table.end());
        food_item.erase(unique(food_item.begin(),food_item.end()),food_item.end());
        vector<vector<string>> res(table.size()+1,vector<string>(food_item.size()+1));
        res[0][0]="Table";
        for(int i=1;i<=food_item.size();i++){
            res[0][i]=food_item[i-1];
        }
        for(int i=1;i<=table.size();i++){
            res[i][0]=table[i-1];
        }
        for(int i=1;i<=table.size();i++){
            for(int j=1;j<=food_item.size();j++){
                res[i][j]=to_string(mp[{table[i-1],food_item[j-1]}]);
            }
        }
        return res;
    }
};