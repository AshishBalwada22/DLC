https://leetcode.com/problems/design-task-manager/?envType=daily-question&envId=2025-09-18

class TaskManager {
public:
    struct comparator{
        static bool operator()(const pair<int,int>&p1,const pair<int,int>&p2){
            if(p1.first==p2.first) return p1.second>p2.second;
            return p1.first>p2.first;
        }
    };
    unordered_map<int,int>m1; // {taskid, userid}
    unordered_map<int,int>m2; // {taskid, priority}
    set<pair<int,int>,comparator>s; // {priority,taskid}
    TaskManager(vector<vector<int>>& tasks) {
        for(auto v:tasks){
            int taskid = v[1];
            int userid = v[0];
            int priority = v[2];
            m1[taskid] = userid;
            m2[taskid] = priority;
            s.insert({priority,taskid});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        m1[taskId] = userId;
        m2[taskId] = priority;
        s.insert({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int oldpriority = m2[taskId];
        m2[taskId] = newPriority;
        s.erase({oldpriority,taskId});
        s.insert({newPriority,taskId});
    }
    
    void rmv(int taskId) {
        int priority = m2[taskId];
        m1.erase(taskId);
        m2.erase(taskId);
        s.erase({priority,taskId});
    }
    
    int execTop() {
        if(s.empty()) return -1;
        int taskid = s.begin()->second;
        int userid = m1[taskid];
        m1.erase(taskid);
        m2.erase(taskid);
        s.erase(s.begin());
        return userid;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */