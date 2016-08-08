#include <iostream>
#include <unordered_map>
#include <list>
#include "../utils.hpp"


using namespace std;


struct LRUCache {
    LRUCache (int capacity);
    int get (int key);
    void set (int key, int get);
};

struct data_t {
    int key;
    int value;
};

std::ostream& operator<< (ostream& out, const data_t& d)
{
    out << "(" << d.key << ", " << d.value << ")";
    return out;
}



std::unordered_map<int, std::list<data_t>::iterator> K;
std::list<data_t> L;

int C; 

LRUCache::LRUCache(int capacity) {
    L.clear();
    K.clear();
    C = capacity;
}

int LRUCache::get(int key) {
    int res = -1;
    if (K.find(key) != K.end()) {
        data_t tmp = *K[key];
        L.push_front(tmp);
        L.erase(K[key]);
        K[key] = L.begin();
    }

    return res;
}

void LRUCache::set(int key, int value) {
    debug (L.size());
    if (K.find(key) != K.end()) {
        data_t tmp = *K[key];
        L.push_front(tmp);
        L.erase(K[key]);
        K[key] = L.begin();
    } else {
        if (L.size() >=  C) {
            auto last = L.back();
            L.pop_back();
            K.erase(last.key);
        }
        L.push_front(data_t{key, value});
        K[key] = L.begin();
    }
}



int main (void)
{
    LRUCache cache(1);

    return 0;
}
