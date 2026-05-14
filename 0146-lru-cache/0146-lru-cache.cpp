class LRUCache {
private:
    int                                                capacity;
    list<pair<int, int>>                               cache;
    unordered_map<int, list<pair<int, int>>::iterator> keys;
public:
    LRUCache(int capacity) : capacity{capacity} {}
    
    int get(int key) {
        if (keys.find(key) != keys.end()) {
            auto kv = *keys[key]; 
            cache.erase(keys[key]);
            cache.push_front(kv);
            keys[key] = cache.begin();
            return kv.second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (keys.find(key) != keys.end()) {
            auto kv = *keys[key]; 
            cache.erase(keys[key]);
            cache.push_front({key, value});
            keys[key] = cache.begin();
        }
        else {
            while (keys.size() >= capacity) {
                auto kv = cache.back();
                cache.pop_back();
                keys.erase(kv.first);
            }
            cache.push_front({key, value});
            keys[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */