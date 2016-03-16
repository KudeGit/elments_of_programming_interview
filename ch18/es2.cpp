#include <iostream>
#include <vector>

int min_waiting_time (std::vector<int> service_times)
{
    std::sort(service_times.begin(), service_times.end());
    int waiting_time = 0;
    for (int i = 0; i < service_times.size(); ++i) {
        waiting_time += service_times[i] * (service_times.size() - i - 1);
    }
    return waiting_time;
}


int main (void) 
{
    std::vector<int> A = {1,2,3};
    std::cout << min_waiting_time(A) << std::endl;
    return 0;
}
