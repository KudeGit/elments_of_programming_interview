#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <fstream>
#include <vector>
#include <random>
#include "../utils.hpp"

struct pq_element {
    std::string data;
    int source;
    long timestamp;
};
std::ostream& operator<< (std::ostream& out, const pq_element& el)
{
    out << el.timestamp << ": " << el.data;
    return out;
}

using pq_container_t = std::vector<pq_element>;
auto pq_compare_t = [](const pq_element& a, const pq_element& b)
    {return a.timestamp > b.timestamp;};
using pq_t = std::priority_queue<pq_element, pq_container_t, decltype(pq_compare_t)>;




std::vector<std::ifstream> init_input_file_streams(const std::vector<std::string>& files)
{
    std::vector<std::ifstream> input_files(files.size());
    for (int i = 0; i < files.size(); ++i) {
        input_files[i].open(files[i], std::ios_base::in);
        if(!input_files[i].good()) {
            exit(1);
        }
    }
    return input_files;
}

void init_pq (std::vector<std::ifstream>& files, pq_t& pq)
{
    for (int i = 0; i < files.size(); ++i) {
        auto& f = files[i];
        std::string line;
        std::getline(f, line);
        if (f) {
            std::stringstream iss(line);
            std::string timestamp;
            std::getline(iss, timestamp, ',');
            pq_element new_el = {.data = line, .source = i, .timestamp=std::stol(timestamp)};
            pq.push(new_el);
        }
    }
    return;
}

pq_element get_next_element(const pq_element& curr, std::vector<std::ifstream>& files)
{
    auto& f = files[curr.source];
    std::string line;
    std::getline(f, line);
    pq_element new_el;
    if(f) {
        std::stringstream iss(line);
        std::string timestamp;
        std::getline(iss, timestamp, ',');
        new_el = {.data = line, .source = curr.source, .timestamp=std::stol(timestamp)};
    } else {
        new_el = {.data = line, .source = curr.source, .timestamp=-1};
    }
    return new_el;
}

void sort_stocks_files (const std::vector<std::string>& files, std::string& out_file_name)
{
    std::priority_queue<pq_element, pq_container_t, decltype(pq_compare_t)> pq(pq_compare_t);
    std::ofstream out_file(out_file_name);
    if (!out_file.good()) {
        return;
    }
    auto input_files = init_input_file_streams(files);
    init_pq(input_files, pq);
    while (!pq.empty()) {
        const pq_element& top_el = pq.top();
        out_file << top_el.data << std::endl;
        auto next_el = get_next_element(top_el, input_files);
        pq.pop();
        if (next_el.timestamp != -1) {
            pq.push(next_el);
        }
    }
    for (auto& f: input_files) {
        f.close();
    }
    out_file.close();

}

void generate_files (const std::vector<std::string>& fnames)
{
    std::random_device rd;
    std::default_random_engine g(rd());
    std::uniform_int_distribution<long> timestamps_dist(0, 10);
    std::uniform_int_distribution<int> draws_dis(0, 10);
    std::uniform_real_distribution<double> stock_price_dist(0,100);
    for (const auto& f: fnames) {
        std::ofstream ofile(f);
        if(!ofile.good()) {
            std::cout << "error opening " << f << std::endl;
            exit(1);
        }
        int n_entries = draws_dis(g);
        std::vector<pq_element> stocks;
        for(int i = 0; i < n_entries; ++i) {
            std::stringstream ss;
            auto timestamp = timestamps_dist(g);
            ss <<  timestamp << "," << f << "," << stock_price_dist(g);
            pq_element curr = {.timestamp = timestamp, .data = ss.str()};
            stocks.push_back(curr);
        }
        std::sort(stocks.begin(), stocks.end(), [](const pq_element& a, const pq_element& b) {
                    return a.timestamp < b.timestamp;
                });
        for(const auto& s: stocks) {
            ofile << s.data << std::endl;
        }
        ofile.close();
    }


}

int main (void)
{
    std::vector<std::string> files  = {"test_apple", "test_google", "test_cisco"};
    std::string output("test_stock");
    generate_files(files);
    sort_stocks_files(files, output);
    return 0;

}
