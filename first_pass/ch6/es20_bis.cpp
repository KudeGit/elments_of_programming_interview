#include <iostream>
#include <vector>
#include <random>
#include <unordered_map>
#include "../utils.hpp"

double draw_number(const std::vector<double>& values, std::vector<double> P)
{
    std::random_device rd;
    std::default_random_engine g(rd());
    std::uniform_real_distribution<double> d(0,1);
    for (int i = 1; i < P.size(); ++i) {
        P[i] += P[i-1];
    }
    double k = d(g);
    int i = 0;
    for (i = 0; i < P.size() && k > P[i]; ++i);

    return values[i];
}



int main (void) 
{
    std::vector<double> vals = {0.0,1.0,2.0};
    std::vector<double> p = {0.2, 0.6, 0.2};
    std::unordered_map<double, double> hist;

    for (const auto& v: vals) {
        hist[v] = 0;
    }

    for (int i  = 0; i < 10000; ++i) {
        int t = draw_number(vals, p);
        hist[t]++;
    }
    for (const auto& h: hist) {
        std::cout << h.first << ": " << h.second/10000 << std::endl;
    }

    return 0;
}


