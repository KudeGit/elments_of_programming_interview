#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void indirect_sort (const std::string& ifilename, const std::string& ofilename)
{
    std::ifstream ifile(ifilename);
    if (!ifile.good()) {
        return;
    }
    std::string line;
    std::vector<std::string> strs;
    while(getline(ifile, line)) {
        strs.emplace_back(line);
    }
    std::vector<std::string*> strs_ptr;
    for (auto& str: strs) {
        strs_ptr.emplace_back(&str);
    }
    std::sort(strs_ptr.begin(), strs_ptr.end(),
                [](const std::string* lhs, const std::string* rhs) {
                    return *lhs < *rhs;
                });
    std::ofstream ofile(ofilename);
    if (!ofile.good()) {
        return;
    }
    for (const auto& str_ptr: strs_ptr) {
        ofile << *str_ptr << std::endl;
    }
    ofile.close();
    ifile.close();
    return;
}
