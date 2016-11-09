#include <iostream>
#include <string>
#include <sstream>
#include <queue>


//k max displacement
void almost_sorted (std::stringstream& ss_in, std::stringstream& ss_out, int k)
{
    if (k < 1) {
        throw std::invalid_argument("K must be at least 1");
    }
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int n;
    while (ss_in >> n) {
        if (pq.size() > k) {
            ss_out << pq.top() << " ";
            pq.pop();
        }
        pq.push(n);
    }
    while (!pq.empty()){
        ss_out << pq.top() << " ";
        pq.pop();
    }
}
