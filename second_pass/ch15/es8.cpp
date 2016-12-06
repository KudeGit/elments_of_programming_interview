#include <iostream>
#include <sstream>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>
#include <limits>
#include "es8.hpp"


bool operator< (const Entry& lhs, const Entry& rhs)
{
    return lhs.count < rhs.count;
}



void PageRank::add (const std::string& url)
{
    auto x = url_2_freq.find(url);
    auto it = freq.end();
    if (x == url_2_freq.end()) {
        it = freq.insert(Entry{url, 1}).first;
    } else {
        it = url_2_freq[url];
        auto old_count = it->count;
        freq.erase(it);
        it = freq.insert(Entry{url, old_count + 1}).first;
    }

    if (it == freq.end()) {
        throw std::logic_error("something is wrong");
    }
    url_2_freq[url] = it;
}

void PageRank::add (const std::pair<long int, std::string>& url)
{
    if (W == 0) {
        add(url.second);
        return;
    }
    auto it = time_list.begin();
    while (!time_list.empty() && it->first - url.first > W) {
        auto url_2_freq_it = it->second;
        if(url_2_freq_it->second->count == 1) {
            freq.erase(url_2_freq_it->second);
            url_2_freq.erase(url_2_freq_it);
        } else {
            auto old_count = url_2_freq_it->second->count;
            freq.erase(url_2_freq_it->second);
            url_2_freq[url.second] = freq.insert(Entry{url.second, old_count - 1}).first;
        }
        time_list.pop_front();
    }

}



std::vector<Entry> PageRank::common(int k)
{
    std::vector<Entry> res;
    long int largest_freq = std::numeric_limits<long int>::max();
    for (auto it = freq.crbegin(); it != freq.crend() && k; ++it, --k) {
        res.emplace_back(*it);
    }
    return res;
}
