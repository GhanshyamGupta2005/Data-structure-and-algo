class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //copy paste from course schedule question
        // we have to restuen our topo sort only


         vector<int> indegree(numCourses, 0); // Initialize indegree for each course
        
        // Calculate indegree for each course
        for(auto it : prerequisites) {
            indegree[it[0]]++;//uss couse ki indegree bahda raha h us pr jakr
        }

        queue<int> q;

        // Push courses with an indegree of 0 into the queue
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while(!q.empty()) {
            int node = q.front();
            topo.push_back(node);
            q.pop();
            
            // Reduce indegree of neighboring courses
            for(auto it : prerequisites) {
                if(it[1] == node) {
                    indegree[it[0]]--;//connections remove kr raha hai
                    if(indegree[it[0]] == 0)
                        q.push(it[0]);
                }
            }
        }

        if (topo.size() == numCourses)
        return topo;
        else
        return {};
    }
};
