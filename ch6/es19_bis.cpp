#include <iostream>
#include <vector>
#include <random>
#include <sstream>

template<class T>
void online_sampling (const std::stringstream& iss, int k)
{
    std::vector<T> samples;
    T x;
    std::random_device rd;
    std::default_random_engine g;
    std::uniform_int_distribution<> d(0, k -1);
    while (iss >> x) {
        if (samples.size() < k) {
            samples.push_back(x);
        } else {
            int i = d(g);
            std::swap(samples[i], samples.back());
            samples.pop_back();
            samples.push_back(x);
        }
    }
    return x;
}

int main (void) 
{
    return 0;
}
