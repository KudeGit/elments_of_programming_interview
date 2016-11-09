#ifndef __CH_11__
#define __CH_11__


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>


struct stock_entry {
    size_t time_of_day;
    std::string company_name;
    size_t n_shares;
    double price;
    std::ifstream* stock_ifstream;
    stock_entry(std::string& line, std::ifstream* stock_file_stream) {
        //in reality we would need input validation with regex 
        std::replace(line.begin(), line.end(), ',', ' ');
        std::stringstream ss(line);
        ss >> time_of_day >> company_name >> n_shares >> price;
        stock_ifstream = stock_file_stream;
    }
    private:
        stock_entry():stock_ifstream(nullptr){};
};

std::ostream& operator<< (std::ostream& out, const stock_entry& s);

void sort_stocks_files (const std::vector<std::string>& in_stock_file_list,
        const std::string& out_file_name = "stock_sorted.txt");


void sort_stocks_files (std::vector<std::ifstream>& in_file_streams,
        std::ofstream& out_file);


void almost_sorted (std::stringstream& ss_in, std::stringstream& ss_out, int k);
std::vector<int> compute_fair_bonuses (const std::vector<int>& locs);

std::vector<int> find_k_closest_to_median (std::vector<int>& A, const int k);

class MedianFinder {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minH; //larger part
    std::priority_queue<int, std::vector<int>, std::less<int>> maxH; //smaller part
    template <class OP1, class OP2>
        inline void push_and_rebalance (std::priority_queue<int, std::vector<int>, OP1>& A,
                std::priority_queue<int, std::vector<int>, OP2>& B,
                const int num, const int threshold);
    public:
        void addNum(int num);
        double findMedian();
};
#endif //__CH_11__
