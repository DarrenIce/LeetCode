class LRUCache {
public:
    LRUCache(int capacity) {
        size_=capacity;
    }
    
    int get(int key) {
        auto it=m.find(key);
        if (it!=m.end()) {
            cache.splice(cache.begin(),cache,it->second);
            return it->second->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it=m.find(key);
        if (it!=m.end()) {
            it->second->second=value;
            return cache.splice(cache.begin(),cache,it->second);
        }
        cache.insert(cache.begin(),make_pair(key,value));
        m[key]=cache.begin();
        if (m.size()>size_) {
            m.erase(cache.back().first);
            cache.pop_back();
        }
    }
private:
    int size_;
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>>::iterator> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */