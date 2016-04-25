#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unordered_map>
#include <string>

struct SetEntry {
    std::string page;
    int freq;
};
bool operator< (const SetEntry& a, const SetEntry& b) {
    return a.freq < b.freq;
}

class RankPage {
    private: 
        std::set<SetEntry> BST;
        using BST_IT_t = std::set<SetEntry>::iterator;
        std::unordered_map<std::string, BST_IT_t> page_map;

    public:
        void insert (const std::string& page) {
            int freq = 0;
            if (page_map.find(page) != page_map.end()) {
                auto bst_it = page_map[page];
                BST.erase(bst_it);
            }
            auto is_good = BST.insert(SetEntry{page, freq});
            if (!is_good.second) {
                throw std::runtime_error("Cannot insert page in BST");
            }
            page_map[page] = is_good.first;
        }

        std::list<std::string> common(int K) {
            std::list<std::string> res;
            auto it = BST.crbegin();
            while (it != BST.crend() && K > 0) {
                res.push_front(it->page);
                ++it;
            }
            return res;
        }
};



int main (void)
{
    return 0;
}
