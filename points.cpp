#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <limits>
#include "utils.hpp"



using line_t = std::tuple<int, int, int, int>;
using namespace std;


ostream& operator<< (ostream& out, const line_t& l) 
{
    out << "(" << get<0>(l) << ", " <<
        get<1>(l) << ", " <<
        get<2>(l) << ", " <<
        get<3>(l) << ")";
    return out;

}



long int gdc (int x, int y) {
    if (x == 0) {
        return y;
    } else if (y == 0){
        return x;
    } else if (((x & 0x1) == 0) && ((y & 0x1) == 0)) {
        return gdc(x>>1, y >>1) << 1;
    } else if (((x & 0x1) == 0) && ((y & 0x1) == 1)) {
        return gdc( x>> 1, y); 
    } else if (((x & 0x1) == 1) && ((y & 0x1) == 0)) {
        return gdc( x, y >> 1);
    } else if (x > y) {
        return gdc(x-y, y);
    } else {
        return gdc(y-x, x);
    }
}

struct KeyHash {
    size_t operator() (const line_t& l) const {
        return std::hash<int>()(get<0>(l)) ^
            std::hash<int>()(get<1>(l)) ^
            std::hash<int>()(get<2>(l)) ^
            std::hash<int>()(get<3>(l));
    }
};


struct KeyEqual {
    bool operator() (const line_t& a, const line_t& b) const {
        return (get<0>(a) == get<0>(b)) &&
            (get<1>(a) == get<1>(b)) &&
            (get<2>(a) == get<2>(b)) &&
            (get<3>(a) == get<3>(b));
    }
};

line_t compute_line (const int x1, const int x2, const int y1, const int y2)
{
    int m1 = (y2 - y1), abs_m2 = abs(y2 - y1);
    int m2 = (x2 - x1), abs_m1 = abs(x2 - x1);
    if (m2 != 0) {
        int m = gdc(abs_m1, abs_m2);
        m1 /= m;
        m2 /= m;
        if(m1*m2 < 0) {
            m1 = -abs(m1);
            m2 = abs(m2);
        } else {
            m1 = abs(m1);
            m2 = abs(m2);
        }

        int q1 = -m1 * x1 + m2 * y1;
        int abs_q1 = abs(q1);
        int q2 = m2, abs_q2 = abs(q2);
        int q = gdc(abs_q1, abs_q2);
        q1 /= q;
        q2 /= q;
        
        if (q1 * q2 < 0) {
            q1 = -abs(q1);
            q2 = abs(q2);
        } else {
            q1 = abs(q1);
            q2 = abs(q2);
        }

        return std::make_tuple(m1,m2,q1,q2);
    } else {
        int m1 = x1;
        int m2 = x1;
        int q1 = x1;
        int q2 = x1;
        return std::make_tuple(m1,m2,q1,q2);
    }
}

bool is_crossing (const line_t& l, const int x, const int y)
{
    double m1 = get<0>(l), m2 = get<1>(l), q1 = get<2>(l), q2 = get<3>(l);
    if (m2 != 0 || q2 != 0) {
        debug(y);
        debug(m1/m2*static_cast<double>(x) + q1/q2);
        return (y - m1/m2*static_cast<double>(x) - q1/q2) < 0.000000001;
    } else {
        return static_cast<double>(x) == q1;
    }

}


int max_point_per_line (const std::vector<int>& X, const std::vector<int>& Y)

{
    if (X.empty() || Y.empty() || X.size() != Y.size()) {
        return 0;
    }
    if (X.size() == 1) {
        return 1;
    }
    
    int max_points = std::numeric_limits<int>::min();

    std::unordered_map<line_t, int, KeyHash, KeyEqual> p_count;
    for (int i = 0; i < X.size(); ++i) {
        p_count.clear();
        int current_max = 0, same = 0;
        for (int j = i + 1; j < X.size(); ++j) {
            if (X[j] == X[i] && Y[i] == Y[j]) {
                ++same;
                continue;
            }
            auto cl = compute_line(X[i], X[j], Y[i], Y[j]);
            debug(cl);
            if (p_count.find(cl) == p_count.end()) {
                auto& p = p_count[cl];
                p = 2;
            } else {
                ++p_count[cl];
            }
            current_max = std::max(current_max, p_count[cl]);
        }
        current_max += same;
        max_points = std::max(max_points, current_max);
    }
    return max_points;
}

//-18 -17 2 -4 5 -13 -2 20
int main (void)
{
    //std::vector<int> X = {0, 1, -1};
    //std::vector<int> Y = {0, 1, -1};

    //std::vector<int> X = {-6, 5, -18, 2, 5, -2};
    //std::vector<int> Y = {-17, -16, -17, 4, -13, 20};
    
    std::vector<int> X = {1, 1, 1};
    std::vector<int> Y = {0, 4, -1};
    
    
    auto res = max_point_per_line(X,Y);
    cout << res << endl;
    return 0;
}
