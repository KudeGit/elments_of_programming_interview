#ifndef __es_8_HPP__
#define __es_8_HPP__

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>
#include <list>


struct Entry {
    std::string url;
    long int count;
};



struct PageRank {
    long int W = 0;
    std::unordered_map<std::string, std::set<Entry>::iterator> url_2_freq;
    std::set<Entry> freq;
    std::list<std::pair<long int, std::unordered_map<std::string, std::set<Entry>::iterator>::iterator>> time_list;

    void add(const std::string& url);
    void add(const std::pair<long int, std::string>& url);
    std::vector<Entry> common(int k);
};


#endif
