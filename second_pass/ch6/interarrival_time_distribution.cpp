#include <iostream>
#include <vector>
#include <random>


class IAtimeDistribution {
    std::vector<int> iaTime;
    std::vector<double> P;
    std::mt19937 gen;
    std::uniform_real_distribution<double> dist;
    IAtimeDistribution() {}
    public:
    int pick();

    IAtimeDistribution(std::vector<int>& _iaTime, std::vector<double> _P) :iaTime(_iaTime), P(_P) {
        for (auto i = 0; i < P.size(); ++i) {
            P[i] += P[i-1];
        }
        std::random_device rd;
        gen = std::mt19937(rd());
        dist = std::uniform_real_distribution<double>(0, 1);
    }
};


int IAtimeDistribution::pick()
{
    auto x = dist(gen);
    for (int i = 0; i < P.size(); ++i) {
        if (P[i] > x) {
            return iaTime[i];
        }
    }
    return P.back();
}


#define N 100000


int main (void)
{
    std::vector<int> times{0,1,2,3};
    std::vector<double> P{0.7, 0.1, 0.1, 0.1}; //(4,0.25);
    std::vector<int> freq(4, 0);
    IAtimeDistribution solution(times, P);
    for (int i = 0; i < N; ++i) {
        freq[solution.pick()]++;
    }
    for (auto& f: freq) {
        std::cout << static_cast<double>(f)/static_cast<double>(N) << "\n";
    }
    return 0;
}

