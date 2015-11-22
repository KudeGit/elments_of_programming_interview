#include <iostream>
#include <vector>
#include <random>
#include "../utils.hpp"


struct PktArrivalDistribution {
    std::vector<int> _T;
    std::vector<double> _P;

    std::default_random_engine g;
    std::uniform_real_distribution<double> d;
    int get() {
        double coin = d(g);
        int i;
        for (i = 0; i < _T.size() && coin > _P[i]; ++i);
        return _T[i];

    }
    PktArrivalDistribution (const std::vector<int> T, 
                                const std::vector<double> P):
                                _T(T), _P(P) {
        for (int i = 0; i < _P.size(); ++i) {
            _P[i] += _P[i-1];
        }
        d = std::uniform_real_distribution<double>(0.0, 1.0);
    }
};



int main(void) 
{
    std::vector<int> T = {0,1,2,3,4};
    std::vector<int> test(5, 0);
    std::vector<double> P = {0.2, 0.2, 0.2, 0.2, 0.2};
    PktArrivalDistribution pkt_distr(T, P);
    for (int i = 0; i < 10000; ++i) {
        int k = pkt_distr.get();
        ++test[k];

    }
    for (const auto& a: test) {
        double tt = static_cast<double>(a)/10000.0;
        debug(tt);
    }
    return 0;

}

