https://leetcode.com/problems/employee-importance/





//Solution Approach :- Brute Force 
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int result = 0;
        for(auto& emp : employees){
            if(emp-> id == id){
                result = emp->importance;;
                if(!emp->subordinates.empty()){
                    for(auto& s : emp->subordinates){
                        result += getImportance(employees, s);
                    }
                }
                return result;
            }
        }
        return result;
    }
};



//Second Solution :-  DFS but with storing values
class Solution {
public:
    unordered_map<int, Employee*> emap;
    int getImportance(vector<Employee*> employees, int id) {
        for(auto& emp : employees){
            emap[emp->id] = emp;
        }
        return dfs(id);
    }

    int dfs(int id){
        Employee* emp = emap[id];
        int result = emp->importance;
        for(auto& s : emp->subordinates){
            result += dfs(s);
        }
        return result;
    }
};



//Third Solution :- BFS
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int result = 0;
        unordered_map<int, Employee*> emap;
        for(auto& employee : employees){
            emap[employee->id] = employee;
        }

        queue<Employee*> q;
        q.push(emap[id]);
        while (!q.empty()) {
            Employee* emp = q.front();  q.pop();
            result += emp->importance;
            for (int s : emp->subordinates) {
                q.push(emap[s]);
            }
        }
        return result;
    }
};