#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>
#include <stdio.h>


#include "ch11.hpp"


std::ostream& operator<< (std::ostream& out, const stock_entry& s)
{
    out << s.time_of_day << ", " <<
        s.company_name << ", " << s.price;
    return out;
}


void sort_stocks_files (std::vector<std::ifstream>& in_file_streams,
        std::ofstream& out_file)
{

    auto sort_by_time = [](const stock_entry& lhs, const stock_entry& rhs) {
                            return lhs.time_of_day > rhs.time_of_day;
                        };
    std::priority_queue<stock_entry, 
                        std::vector<stock_entry>,
                        decltype(sort_by_time)> pq(sort_by_time);

    for (auto& in_file: in_file_streams) {
        std::string line;
        if (std::getline(in_file, line)) {
            pq.push(stock_entry(line, &in_file));
        }

    }


    if (!out_file.good()) {
        throw std::invalid_argument("cannot open output file");
    }
    
    while (!pq.empty()) {
        auto curr_stock = pq.top();
        out_file << curr_stock << std::endl;
        pq.pop();
        if (curr_stock.stock_ifstream != nullptr &&
                curr_stock.stock_ifstream->good()) {
            std::string line;
            if(getline(*curr_stock.stock_ifstream, line)) {
                pq.push(stock_entry(line, curr_stock.stock_ifstream));
            }
        }

    }
}


void sort_stocks_files (const std::vector<std::string>& in_stock_file_list,
        const std::string& out_file_name)
{
    std::vector<std::ifstream> in_file_streams(in_stock_file_list.size());
    for (size_t i = 0; i < in_stock_file_list.size(); ++i) {
        in_file_streams[i].open(in_stock_file_list[i]);
        if(!in_file_streams[i].good()) {
            throw std::invalid_argument("file does not exists");
        }
    }
    std::ofstream out_file(out_file_name);
    if (!out_file.good()) {
        throw std::invalid_argument("cannot open output file");
    }
    sort_stocks_files(in_file_streams, out_file);
    out_file.close();
    return;

}
