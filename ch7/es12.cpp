#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

int tail_slow (const std::string& filename, const int n_lines)
{


    std::ifstream input_file(filename);
    if(!input_file.good()) {
        std::cout << "Can not open " << filename << std::endl;
        return 1;
    }
    std::vector<std::string> lines(n_lines);
    std::string line;
    int current_index = 0;
    while(getline(input_file, line)) {
        lines[current_index] = line;
        current_index  = (current_index + 1)%n_lines;
    }
    for (int i = 0; i < n_lines; ++i) {
        int k = (current_index+i) % n_lines;
        if(lines[k].size()) {
            std::cout << lines[k] << std::endl;
        }
    }
    return 0;
}

int tail (const std::string& filename, int n_lines)
{
    std::ifstream input_file(filename);
    if(!input_file.good()) {
        std::cout << "Can not open " << filename << std::endl;
        return 1;
    }
    int read_lines = 0; 
    input_file.seekg(0, std::ios::end);
    int file_size = input_file.tellg();
    std::string output;
    for (int i = 0; i < file_size; ++i) {
        char c;
        input_file.seekg(-1-i, std::ios::end);
        input_file.get(c);
        if(c == '\n') {
            ++read_lines;
            if(read_lines > n_lines) {
                break;
            }
        }
        output.push_back(c);
    }
    std::reverse(output.begin(), output.end());
    std::cout << output << std::endl;
    return 0;
}





int main (int argc, char *argv[]) {
    if (argc > 3) {
        std::cout << "usage error: " 
            << argv[0] << " filename <number of lines>"  << std::endl;
        return 1;
    }
    std::string filename(argv[1]);
    int n_lines = 10;
    if (argc == 3) {
        std::stringstream iss(argv[2]);
        iss >> n_lines;
        if (iss.rdbuf()->in_avail()) {
            std::cout << argv[2] << " cannot be parsed." << std::endl;
            return 1;
        }
        if(n_lines < 0) {
            std::cout << "numbers of lines must be larger than zero" << std::endl;
            return 1;
        }
    }
    return tail(filename, n_lines);

}
