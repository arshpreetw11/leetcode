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
    void dfs(int id,unordered_map<int,Employee*>& adj){
        total+=adj[id]->importance;
        if(adj[id]->subordinates.size()==0) return;
        
        for(int sub:adj[id]->subordinates){
            dfs(sub,adj);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        int n=employees.size(); //number of employees;
        
        unordered_map<int,Employee*> adj;
        for(auto &emp:employees){
            
            int ID=emp->id;
            adj[ID]=emp;
        }
        dfs(id,adj);
        return total;
    }
};