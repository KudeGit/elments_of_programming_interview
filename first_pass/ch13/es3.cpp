#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
#include "../utils.hpp"


struct Book {
    std::string isbn;
    //... anything else
    std::string str(void) {
        return isbn;
    }
};


Book get_book_from_db (const std::string& isbn)
{
    return Book{isbn};
}

struct BookHash {
    size_t operator() (const Book& b) {
        return std::hash<std::string>()(b.isbn);
    }
};

struct BookEqual {
    bool operator() (const Book& b1, const Book& b2) {
        return b1.isbn == b2.isbn;
    }
};

template <size_t N, class queryType, class ObjType>
struct LRU {
    std::unordered_map<queryType, typename std::list<ObjType>::iterator> cache;
    std::list<ObjType> objects;
    ObjType get (const queryType& q);
};


template <size_t N, class queryType, class ObjType>
ObjType LRU<N, queryType, ObjType>::get (const queryType& q) 
{
    if (cache.size() != objects.size()) {
        throw std::logic_error("cache and list are out of sync");
    }
    ObjType elem; 
    size_t n_obects = objects.size();
    if (cache.find(q) == cache.end()) {
        error("element not in cache");
        if (n_obects >= N) {
            error("too many elements... removing last");
            auto oldest_elem = objects.back();
            error("last element is %s", oldest_elem.str().c_str());
            cache.erase(oldest_elem.isbn);
            objects.pop_back();
        }
        elem = get_book_from_db(q);
    } else {
        //move the element to the front and update cache
        error("updating cache");
        auto it = cache[q];
        elem = *it;
        objects.erase(it);
    }
    objects.push_front(elem);
    cache[q] = objects.begin();
    return elem;
}


int main (void) 
{
    LRU<5, std::string, Book> cache;
    auto a = cache.get("0");
    auto b = cache.get("1");
    auto c = cache.get("2");
    auto d = cache.get("3");
    auto e = cache.get("4");
    auto f = cache.get("5");
    return 0;
}


