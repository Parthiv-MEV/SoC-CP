class LRUCache {
public:
    int cap = 0;
    vector<pair<int, int>> v;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        for (int i = 0; i < v.size(); ++i) {
            if (v[i].first == key) {
                auto p = v[i];
                v.erase(v.begin() + i);
                v.push_back(p);
                return p.second;
            }
        }
        return -1;
    }

    void put(int key, int value) {
        for (int i = 0; i < v.size(); ++i) {
            if (v[i].first == key) {
                v.erase(v.begin() + i);
                v.push_back({key, value});
                return;
            }
        }
        if (v.size() == cap) {
            v.erase(v.begin()); // remove least recently used
        }
        v.push_back({key, value});
    }
};
