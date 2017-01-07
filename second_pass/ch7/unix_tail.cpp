#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "../../utils.hpp"

using namespace std;

void tail (const string& file_name, int n)
{
    if (n < 1) {
        return;
    }
    ifstream ifile(file_name);
    if (!ifile.good()) {
        return;
    }
    ifile.seekg(0, ios::end);
    auto file_size = ifile.tellg();
    string res;
    for (int i = 0; i < file_size && n >= 0 ; ++i) {
        ifile.seekg(-1-i, ios::end);
        char c;
        ifile.get(c);
        if (c == '\n') {
            --n;
        }
        res += c;
    }
    std::reverse(res.begin(), res.end());
    cout << res << endl;
    return;
}


int main (int argc, char* argv[])
{
    if (argc != 3) {
        std::cerr << "usage error: " << argv[0] << " filename number_of_lines" << endl;
        return 1;
    }

    string file_name(argv[1]);
    auto n = stoi(argv[2]);
    tail(file_name, n);
    return 0;
}
