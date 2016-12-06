#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>

std::string find_top_student (const std::vector<std::pair<std::string, int>>& scores)
{
    std::unordered_map<std::string, std::multiset<int>> students_to_scores;
    for (auto& score: scores) {
        auto& x = students_to_scores[score.first];
        x.insert(score.second);
        if (x.size() > 3) {
            x.erase(x.begin());
        }
    }
    auto max_mean = -1.0;
    auto student_max_mean = std::string("");
    for (auto& student_to_score: students_to_scores) {
        auto student = student_to_score.first;
        auto c_mean = 0.0;
        if (student_to_score.second.size() == 3) {
            for (auto& score: student_to_score.second) {
                c_mean += score;
            }
            c_mean /= 3.0;
            if (c_mean > max_mean) {
                max_mean = c_mean;
                student_max_mean = student;
            }
        }
    }
    return student_max_mean.empty() ? "no such student" : student_max_mean;

}
