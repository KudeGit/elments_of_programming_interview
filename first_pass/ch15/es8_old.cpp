#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <set>
#include "../utils.hpp"

struct Page {
    std::string content;
    size_t hits;
};

std::ostream& operator<< (std::ostream& out, const Page& p)
{
    out << "(" << p.content << ", " << p.hits << ")";
    return out;
}

bool operator< (const Page& p1, const Page& p2) 
{
    return p1.hits < p2.hits;
}


struct Internet
{
    virtual void add_entry (Page& p) = 0;
    virtual std::list<Page> common(int k) = 0;
};
//part 1: 
//first do add entry for all the pages
//and assume common is called after
struct Internet1 : Internet {
    static bool is_sorted;
    std::unordered_map<std::string, Page> map_hits;
    std::list<Page> sorted_page;
    virtual void add_entry(Page& p) {
        if(map_hits.find(p.content) == map_hits.end()) {
            map_hits[p.content] = p;
            map_hits[p.content].hits = 1;
        } else {
            ++map_hits[p.content].hits;
        }
    }
    
    void prepare_sorted_list (void) {
        for (const auto& page: map_hits) {
            auto p = page.second;
            auto it = sorted_page.begin();
            while (it != sorted_page.end() && it->hits > p.hits) {
                ++it;
            }
            sorted_page.insert(it, p);
        }
        is_sorted = true;
    }

    virtual std::list<Page> common(int k) {
        if(!is_sorted) {
            prepare_sorted_list();
        }
        std::list<Page> res;
        auto it = sorted_page.begin();
        while (it != sorted_page.end() && k > 0) {
            res.push_back(*it);
            ++it;
            --k;
        }
        return res;
    }
};

bool Internet1::is_sorted = false;


struct myCompare {
    bool operator() (const std::unordered_map<std::string, Page>::const_iterator &a,
            const std::unordered_map<std::string, Page>::const_iterator &b) const {
        return a->second.hits < b->second.hits;
    }

};

struct Internet2 : Internet 
{
    std::unordered_map<std::string, Page> page_freq;
    std::unordered_map<std::string, std::set<std::unordered_map<std::string, Page>::iterator, myCompare>::iterator> page_to_bst;
    std::set<std::unordered_map<std::string, Page>::iterator, myCompare> bst;

    void add_entry (Page& p) {
        if (page_freq.find(p.content) == page_freq.end()) {
            std::pair<std::unordered_map<std::string, Page>::iterator,bool>   res_freq = page_freq.insert({p.content, Page{p.content, 0}});
            ++page_freq[p.content].hits;
            std::pair<std::set<std::unordered_map<std::string, Page>::iterator, myCompare>::iterator,  bool>  res_bst = bst.insert(res_freq.first);
            std::set<std::unordered_map<std::string, Page>::iterator, myCompare>::iterator it;
            page_to_bst[p.content] = it;
        } else {
            ++page_freq[p.content].hits;
            //get element in bst and remove it
            auto bst_it = page_to_bst[p.content];
            bst.erase(bst_it);
            auto res_bst = bst.insert(page_freq.find(p.content));
            if (res_bst.second == false) {
                throw std::logic_error("Something is wrong");
            }
            page_to_bst[p.content] = res_bst.first;
        }
    }
    virtual std::list<Page> common(int k) {
        return {};
    }

};




int main (void)
{
    Internet2 i2; 

    //for (int i = 0 ; i < 5; i++) {
    //    std::stringstream ss;
    //    ss << "Page" << i;
        Page p = {.content = "test", .hits = 0};
    //    for (int j = 0; j <= i; ++j) {
            i2.add_entry(p);
    //    }
    //}

    //auto res = i1.common(3);

    //std::cout << res << std::endl;


}
