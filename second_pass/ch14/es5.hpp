#ifndef __ES5_HPP__
#define __ES5_HPP__
#include <iostream>
#include <utility>

using Event = std::pair<std::size_t, std::size_t>;
int max_concurrent_events (const std::vector<Event>& events);


#endif  //__ES5_HPP__
