#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>
#include "../utils.hpp"

long int GDC (long long a, long long b)
{
    if (a == 0) {
        return b;
    } else if (b == 0) {
        return a;
    } else if (!(a & 0x01ll) && !(b & 0x01ll)) {
        return (GDC(a >> 1, b >> 1) << 1);
    } else if ( !(a &0x01ll) && (b & 0x01ll)) {
        return GDC(a >> 1, b);
    } else if ( (a &0x01ll) && !(b & 0x01ll)) {
        return GDC(a, b >> 1);
    } else {
        if (a > b) {
            return GDC(a - b, b);
        } else {
            return GDC(b - a, a);
        }
    }
}

struct Point {
    int x;
    int y;
};

struct Line {
    double m;
    double q;
    void swap(Line& other) {
        std::swap(m, other.m);
        std::swap(q, other.q);
    }
    Line(): m(0), q(0) {};
    Line(int _m, int _q): m(_m), q(_q){};
    Line(const Point& p1, const Point& p2);
    ~Line() {};
    Line (const Line& other) : m(other.m), q(other.q) {}

    Line& operator= (Line other) {
        swap(other);
        return *this;
    }
    Line (Line&& other) : m(std::move(other.m)), q(std::move(other.q)) {}
    bool cross(const Point& p) const {
        return m*p.x + q == p.y;
    }
};

Line::Line (const Point& p1, const Point& p2)
{
    int m1 = (p1.y - p2.y);
    int m2 = (p1.x - p2.x);
    if (m2 == 0) {
        m = 0;
        q = p1.y;
        return;
    }
    int gdc = GDC(abs(m1),abs(m2));
    m1 /= gdc;
    m2 /= gdc;
    m = m1/m2;
    q = -p1.x * m + p1.y;
}
std::ostream& operator<< (std::ostream& out, const Line& l)
{
    out << "(" <<l.m << ", " << l.q << ")";
    return out;
}


int count_points (const Line& line, const std::vector<Point>& points)
{
    int count = 0;
    for (const auto& p: points) {
        count = line.cross(p) ? count + 1 : count;
    }
    return count;
}

struct LineHash {
    size_t operator() (const Line& l) const {
        return std::hash<double>()(l.m)^std::hash<double>()(l.q);
    }
};
struct LineEqual {
    bool operator() (const Line& lhs, const Line& rhs) const {
        return lhs.m == rhs.m && lhs.q == rhs.q;
    }
};


Line find_line (const std::vector<Point>& points)
{
    if (points.size() < 2) {
        throw std::invalid_argument("no point was provided");
    }
    std::unordered_map<Line, int, LineHash, LineEqual> points_per_line;
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 1; j < points.size(); ++j) {
            Line curr(points[i], points[j]);
            if (points_per_line.find(curr) == points_per_line.end()) {
                points_per_line[curr] = count_points(curr, points);
            }
        }
    }
    int max_points = std::numeric_limits<int>::min();
    Line res;
    for (const auto& pl: points_per_line) {
        auto n_points = pl.second;
        auto curr_line = pl.first;
        res = n_points > max_points ? curr_line : res;
    }
    return res;
}

int main (void)
{

    std::vector<Point> points = { Point{0, 1}, Point{1,3}, Point{2,6}};
    auto line = find_line(points);
    std::cout << line << std::endl;
    return 0;
}


