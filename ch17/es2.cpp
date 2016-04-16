#include <iostream>
#include <string>
#include <vector>
#include "../utils.hpp"

int edit_distance (const std::string& a, const std::string& b)
{
    std::vector<std::vector<int>> K(a.size() + 1, std::vector<int>(b.size() + 1));
    for (int i = 0; i <= a.size(); ++i) {
        K[i][0] = i;
    }
    for (int i = 0; i <= b.size(); ++i) {
        K[0][i] = i;
    }
    for (int i = 1; i <= a.size(); ++i) {
        for (int j = 0; j <= b.size(); ++j) {
            int dij = a[i] == b[j] ? 0 : 1;
            K[i][j] = std::min(std::min(K[i-1][j] + 1, K[i][j-1] + 1), K[i-1][j-1] + dij);
        }
    }
    return K.back().back();
}

int main (void)
{
    std::string a("exponential");
    std::string b("polynomial");
    std::cout << edit_distance(a, b) << std::endl;
    return 0;
}
