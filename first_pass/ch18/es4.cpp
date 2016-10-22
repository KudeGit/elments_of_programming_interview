#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>



bool assign_to_servers(const std::vector<int> user_bytes, 
        std::vector<int>& users_to_servers, const int limit, const int n_servers)
{
    int server_idx = 0;
    std::vector<int> capacity(n_servers, 0);
    for (int i = 0; i < user_bytes.size(); ++i) {
        while (server_idx < users_to_servers.size() && 
                capacity[server_idx] + user_bytes[i] > limit) {
            ++server_idx;
        }
        if (server_idx >= users_to_servers.size()) {
            return false;
        } else{
            users_to_servers[i] = server_idx;
            capacity[server_idx] += user_bytes[i];
        }
    }
    return true;
}

std::vector<int> decide_load_balancing(const std::vector<int> user_bytes, const int n_servers)
{
    const int tot_bytes = std::accumulate(user_bytes.begin(), user_bytes.end(), 0);
    int min_bytes = 0;
    int max_bytes = tot_bytes;
    std::vector<int> users_to_servers(user_bytes.size(), 0);
    auto byte_limit_candidate = max_bytes;
    while (min_bytes < max_bytes) {
        auto next_byte_limit_candidate = min_bytes + ((max_bytes - min_bytes) >> 1);
        auto is_feasible = assign_to_servers(user_bytes, users_to_servers, next_byte_limit_candidate, n_servers);
        if (is_feasible) {
            max_bytes = next_byte_limit_candidate - 1;
        } else {
            min_bytes = next_byte_limit_candidate + 1;
        }
    }
    return users_to_servers;
}


int main (void)
{
    std::vector<int> user_bytes = {1,2,3,4,5,6,7,10}
    return 0;

}

