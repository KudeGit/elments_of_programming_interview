#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include "../utils.hpp"

std::string normalize_path (const std::string& path)
{
    if(path.empty()) {
        return "";
    }
    std::vector<std::string> s;
    if (path.front() == '/') {
        s.push_back("/");
    }
    std::stringstream ss(path);
    std::string current;
    while (getline(ss, current, '/')) {
        if (current == "..") {
            if (s.empty() || s.back() == "..") {
                s.push_back(current);
            } else {
                if(s.back() == "/") {
                    throw std::invalid_argument("invalid path");
                }
                s.pop_back();
            }
        } else if (current != "." && current != "") {
            for (const auto c: current) {
                if (!isalnum(c)) {
                    throw std::invalid_argument("invalid path");
                }
            }
            s.push_back(current);
        }
    }

    std::string npath("");
    if (!s.empty()) {
        auto it = s.cbegin();
        npath += *it; ++it;
        while (it != s.cend()) {
            if (*(it - 1) != "/") {
                npath += "/";
            }
            npath += *it; ++it;
        }
    }
    return npath;
}


int main (int argc, const char* argv[])
{
    if(argc != 2) {
        error("usage %s error: %s path", argv[0], argv[0]);
        return -1;
    }
    std::string path(argv[1]);
    try{
        auto npath = normalize_path(path);
        std::cout << argv[1] << " => " << npath << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
