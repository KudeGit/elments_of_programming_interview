#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "../utils.hpp"


void tail_file (const std::string& fname, int k)
{
    if (fname.empty()) {
        return;
    }
    std::ifstream ifile(fname, std::ios::in);
    if (!ifile.good()) {
        return;
    }
    std::string output("");
    ifile.seekg(0, std::ios::end);
    auto end = ifile.tellg();
    int n_lines = 0;
    char c;

    for (int i = 0; i < end && n_lines < k; ++i) {
        ifile.seekg( -1 - i, std::ios::end);
        ifile.get(c);
        if(c == '\n') {
            ++n_lines;
        }
        debug(c);
        output.push_back(c);
    }
    std::reverse(output.begin(), output.end());
    banner();
    std::cout << output;
    banner();
    return;
}


int main (int argc, char* argv[])
{
    if (argc != 3) {
        error("error usage: %s file num_lines", argv[0]);
        return -1;
    }
    int k = std::stoi(argv[2]);
    tail_file(argv[1], k);
    return 0;
}
