/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int total=0;
    void dfs(int id,unordered_map<int,pair<int,vector<int>>>& adj){
        total+=adj[id].first;
        if(adj[id].second.size()==0) return;
        
        for(int sub:adj[id].second){
            dfs(sub,adj);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        int n=employees.size(); //number of employees;
        
        unordered_map<int,pair<int,vector<int>>> adj;
        for(auto &emp:employees){
            int ID=emp->id;
            int imp=emp->importance;
            vector<int> subor=emp->subordinates;
            adj[ID].first=imp;
            adj[ID].second=subor;
        }
        dfs(id,adj);
        return total;
    }
};