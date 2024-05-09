class LRUCache {
public:
    unordered_map<int, int> mp, uses;
    deque<int> dq;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.count(key)){
            dq.push_back(key);
            uses[key]++;
            if(!dq.empty() && uses[dq.front()] > 1)
                uses[dq.front()]--, dq.pop_front();
            return mp[key];
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.size() == capacity && !mp.count(key)) {
            while (uses[dq.front()] != 1){
                uses[dq.front()]--;
                dq.pop_front();
            }
            uses[dq.front()]--;
            mp.erase(dq.front());
            dq.pop_front();
        } 
        mp[key] = value;
        dq.push_back(key);
        uses[key]++;
    }
};