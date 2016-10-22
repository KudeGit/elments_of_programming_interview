#include <iostream>
#include <vector>
#include <string>
#include "../utils.hpp"

void print_triangle(const std::vector<std::vector<int>> &A)
{
    for(const auto& a: A) {
        std::cout << a << std::endl;
    }
}

std::vector<std::vector<int>> pascal(const int N) 
{
    if (N <= 0) {
        return {};
    }
    std::vector<std::vector<int>> res;
    for(int i = 0; i < N; ++i) {
        std::vector<int> current_line(i+1, 0);
        current_line[0] = current_line.back() = 1;
        for (int j = 1; j < i; ++j) {
            current_line[j] = res[i-1][j-1] + res[i-1][j];
        }
        res.push_back(current_line);
    }
    return res;
}
int main(void)
{
    for (int i = 0; i < 6; ++i) {
        auto A = pascal(i);
        std::cout << std::string(30, '#') << std::endl;
        print_triangle(A);
    }
    return 0;
}
