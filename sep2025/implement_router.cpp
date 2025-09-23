https://leetcode.com/problems/implement-router/description/?envType=daily-question&envId=2025-09-20

class Router {
public:
    class packet{
        public:
        int start; // where packet is generated
        int end;   // where packet is recieved
        int time;  // when packet is recieved
        packet(int st, int en, int t){
            start = st;
            end = en;
            time = t;
        }
    };
    queue<packet>q;// for ordering
    set<string>visited;
    unordered_map<int,vector<int>>m;// destination, time of packets arrived

    int limit;
    Router(int memoryLimit) {
        limit = memoryLimit;
        while(!q.empty()){
            q.pop();
        }
        visited.clear();
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string str = to_string(source) + "$" + to_string(destination) + "$" + to_string(timestamp);
        if(visited.find(str)!=visited.end()) return false;
        if(q.size()==limit){
            packet p = q.front();
            q.pop();
            string str = to_string(p.start) + "$" + to_string(p.end) + "$" + to_string(p.time);
            visited.erase(str);
            // remove the oldest one 
            m[p.end].erase(m[p.end].begin());
        }
        q.push(packet(source,destination,timestamp));
        visited.insert(str);
        m[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.size()==0) return {};
        packet p = q.front();
        q.pop();
        string str = to_string(p.start) + "$" + to_string(p.end) + "$" + to_string(p.time);
        visited.erase(str);
        m[p.end].erase(m[p.end].begin());
        return {p.start,p.end,p.time};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        // packet is stored in ascending order as timestamp
        if(m.find(destination) == m.end()) return 0;
        vector<int>&v = m[destination]; // sorted order
        int lower = lower_bound(v.begin(),v.end(),startTime) - v.begin();
        int upper = upper_bound(v.begin(),v.end(),endTime) - v.begin();
        return upper-lower;

    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */