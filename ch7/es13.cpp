#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include "../utils.hpp"

std::vector<std::string> justify (const std::vector<std::string>& A, int L)
{
    int k = 0;
    std::queue <std::string> q;
    std::vector<std::string> T;
    while (k < A.size()) {
        int c_line_len= 0;
        std::stringstream line;
        q.push(A[k]); c_line_len += A[k++].size();
        while (k < A.size() && (c_line_len + 1 + A[k].size()) <= L) {
            q.push(A[k]);
            c_line_len += 1 + A[k++].size();
        }
        if(q.size() == 1) {//single word case;
            line << q.front() << std::string(L - q.front().size(), ' ');
            q.pop();
        } else { //multiword case
            int n_spaces = q.size() - 1;
            std::vector<int> spaces(n_spaces, 1 + (L - c_line_len)/n_spaces);
            int leftover = (L - c_line_len)%n_spaces;
            for(int i = 0; i < n_spaces && leftover > 0; ++i) {
                ++spaces[i]; --leftover;
            }
            int i = 0;
            line << q.front();
            q.pop();
            while(q.empty() == false && i < n_spaces) {
                std::string s = std::string(spaces[i], ' ');
                line << std::string(spaces[i], ' ') << q.front();
                q.pop(); ++i;
            }
        }
        T.push_back(line.str());
    }
    return T;
}



int main (void) 
{
    std::vector<std::string> words = {
        "the", "quick", "brown", "fox",
        "jumped", "over", "the", "lazy", "dog"};
    auto lines = justify(words, 11);
    for (const auto& l: lines) {
        std::cout << l << std::endl;
    }
    return 0;
}
