#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include "../utils.hpp"




static auto dictionary = load_dictionary();

auto build_production_sequence(std::unordered_map<std::string, std::string>& prev, 
        const std::string& A, const std::string& B)
{
    std::vector<std::string> res;
    auto curr = B;
    while (!curr.empty()) {
        res.emplace_back(curr);
        curr = prev[curr];
    }
    return res;
}

//sequence to transforma A to B chanching one char at the time
std::vector<std::string> production_sequence (const std::string& A, const std::string& B)
{
    std::unordered_map<std::string, std::string> prev;
    prev[A] = "";
    std::queue<std::string> Q;
    Q.push(A);
    while(!Q.empty()) {
        auto curr = Q.front();
        Q.pop();
        for(int i = 0; i < curr.size(); ++i) {
            for (char c = 'a'; c <= 'z'; ++c) {
                auto candidate = curr;
                candidate[i] = c;
                if (candidate == A) {
                    continue;
                }
                if (dictionary.find(candidate) != dictionary.end()) {
                    auto& x = prev[candidate];
                    if (x.empty()) {
                        x = curr;
                        if (candidate == B) {
                            return build_production_sequence(prev, A, B);
                        } else {
                            Q.push(candidate);
                        }
                    } else {
                        //we already passed through here before
                    }
                }
            }
        }
    }
    
    return {};
}


int main (void)
{
    //auto res1 = production_sequence("stack", "smack");
    //std::cout << res1 << std::endl;
    auto res2 = production_sequence("jack", "pick");
    std::cout << res2 << std::endl;
    return 0;


}
